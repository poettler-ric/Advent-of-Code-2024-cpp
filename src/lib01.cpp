#include "lib01.hpp"

#include <catch2/catch_test_macros.hpp>
#include <charconv>
#include <cstddef>
#include <expected>
#include <fstream>
#include <utility>

[[nodiscard]] std::expected<std::pair<int, int>, std::string> parse_line(
    const std::string& line) noexcept {
    std::pair<int, int> result;
    if (std::from_chars(&line[0], &line[5], result.first).ec != std::errc{}) {
        return std::unexpected(std::format(
            R"(couldn't convert first number from "{}" to int)", line));
    }
    if (std::from_chars(&line[8], &line[13], result.second).ec != std::errc{}) {
        return std::unexpected(std::format(
            R"(couldn't convert second number from "{}" to int)", line));
    }
    return result;
}

TEST_CASE("parse_line", "day01") {
    REQUIRE(*parse_line("74540   88907") == std::pair<int, int>{74540, 88907});
}

[[nodiscard]] std::expected<std::pair<int, int>, std::string> day01(
    const std::filesystem::path& day01_file) noexcept {
    std::ifstream infile{day01_file};
    if (!infile.is_open()) {
        return std::unexpected(
            std::format("couldn't open file {}", day01_file.string()));
    }

    std::pair<int, int> result{0, 0};

    std::vector<int> column1;
    std::vector<int> column2;
    std::string line;
    while (std::getline(infile, line)) {
        if (const auto line_result = parse_line(line)) {
            column1.push_back(line_result->first);
            column2.push_back(line_result->second);
        } else {
            return std::unexpected(
                std::format(R"(error whle parsing line "{}": {})", line,
                            line_result.error()));
        }
    }
    std::sort(column1.begin(), column1.end());
    std::sort(column2.begin(), column2.end());

    size_t j{0};
    for (size_t i{0}; i < column1.size(); i++) {
        result.first += column1[i] < column2[i] ? column2[i] - column1[i]
                                                : column1[i] - column2[i];
        int count{0};
        while (column2[j] < column1[i] && j < column2.size()) {
            j++;
        }
        while (column2[j] == column1[i] && j < column2.size()) {
            j++;
            count++;
        }
        result.second += column1[i] * count;
    }

    return result;
}

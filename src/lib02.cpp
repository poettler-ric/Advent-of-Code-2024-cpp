#include "lib02.hpp"

#include <catch2/catch_test_macros.hpp>
#include <charconv>
#include <expected>
#include <fstream>
#include <ranges>
#include <sstream>
#include <utility>

[[nodiscard]] std::expected<std::vector<int>, std::string> parse_line(
    const std::string& line) noexcept {
    std::vector<int> result;
    std::stringstream ss{line};
    std::string token;
    while (std::getline(ss, token, ' ')) {
        int parsed{};
        if (std::from_chars(token.data(), token.data() + token.size(), parsed)
                .ec == std::errc{}) {
            result.push_back(parsed);
        } else {
            return std::unexpected(
                std::format(R"(couldn't parse "{}" to int)", token));
        }
    }
    return result;
}

TEST_CASE("parse_line", "day02") {
    REQUIRE(*parse_line("7 6 4 2 1") == std::vector<int>{7, 6, 4, 2, 1});
}

[[nodiscard]] bool is_safe(const std::vector<int> numbers) noexcept {
    int difference = numbers[0] - numbers[1];
    bool increasing = difference < 0;
    bool valid = increasing ? (difference > -4 && difference < 0)
                            : (difference > 0 && difference < 4);
    if (!valid) {
        return false;
    }
    int previous = numbers[1];
    for (const int& i : numbers | std::views::drop(2)) {
        difference = previous - i;
        valid = increasing ? (difference > -4 && difference < 0)
                           : (difference > 0 && difference < 4);
        if (!valid) {
            return false;
        }
        previous = i;
    }
    return true;
}

TEST_CASE("is_safe", "day02") {
    REQUIRE(is_safe(std::vector<int>{7, 6, 4, 2, 1}) == true);
    REQUIRE(is_safe(std::vector<int>{1, 2, 7, 8, 9}) == false);
    REQUIRE(is_safe(std::vector<int>{9, 7, 6, 2, 1}) == false);
    REQUIRE(is_safe(std::vector<int>{1, 3, 2, 4, 5}) == false);
    REQUIRE(is_safe(std::vector<int>{8, 6, 4, 4, 1}) == false);
    REQUIRE(is_safe(std::vector<int>{1, 3, 6, 7, 9}) == true);
}

[[nodiscard]] std::expected<std::pair<int, int>, std::string> day02(
    const std::filesystem::path& day02_file) noexcept {
    std::ifstream infile{day02_file};
    if (!infile.is_open()) {
        return std::unexpected(
            std::format("couldn't open file {}", day02_file.string()));
    }

    std::pair<int, int> result{0, 0};

    std::string line;
    while (std::getline(infile, line)) {
        if (const auto line_result = parse_line(line)) {
            if (is_safe(*line_result)) {
                result.first++;
            }
        } else {
            return std::unexpected(
                std::format(R"(error while parsing line "{}": {})", line,
                            line_result.error()));
        }
    }

    return result;
}

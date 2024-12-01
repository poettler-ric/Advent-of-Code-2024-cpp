#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <print>

#include "lib01.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::println(std::cerr, "need a file name");
        return EXIT_FAILURE;
    }

    const std::filesystem::path p{argv[1]};
    if (!std::filesystem::exists(p)) {
        std::println(std::cerr, "file {} doesn't exist", p.string());
        return EXIT_FAILURE;
    }

    if (const auto day01_part01_result = day01(p)) {
        std::println("day 01 part 01: {}", day01_part01_result->first);
        std::println("day 01 part 02: {}", day01_part01_result->second);
    } else {
        std::println(std::cerr, "error while doint day 01 part 01: {}",
                     day01_part01_result.error());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <print>

#include "lib02.hpp"

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

    if (const auto day02_part02_result = day02(p)) {
        std::println("day 02 part 02: {}", day02_part02_result->first);
        std::println("day 02 part 02: {}", day02_part02_result->second);
    } else {
        std::println(std::cerr, "error while doint day 02 part 02: {}",
                     day02_part02_result.error());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

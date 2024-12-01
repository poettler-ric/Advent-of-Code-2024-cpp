#ifndef ADVENT_OF_CODE_2024_LIB01_HPP_
#define ADVENT_OF_CODE_2024_LIB01_HPP_

#include <expected>
#include <filesystem>
#include <utility>

[[nodiscard]] std::expected<std::pair<int, int>, std::string> day01(
    const std::filesystem::path& day01_file) noexcept;

#endif

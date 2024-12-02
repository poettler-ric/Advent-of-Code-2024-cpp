#ifndef ADVENT_OF_CODE_2024_LIB02_HPP_
#define ADVENT_OF_CODE_2024_LIB02_HPP_

#include <expected>
#include <filesystem>
#include <utility>

[[nodiscard]] std::expected<std::pair<int, int>, std::string> day02(
    const std::filesystem::path& day02_file) noexcept;

#endif

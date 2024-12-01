add_library (lib01 lib01.hpp lib01.cpp)
target_link_libraries(lib01 PRIVATE Catch2::Catch2)

add_executable(day01 day01.cpp)
target_link_libraries(day01 PRIVATE lib01)

add_executable(test_day01 lib01.cpp)
target_link_libraries(test_day01 PRIVATE Catch2::Catch2WithMain)

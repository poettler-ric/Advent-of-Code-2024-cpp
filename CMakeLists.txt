cmake_minimum_required(VERSION 3.30)

project(advent_of_code_2024_cpp VERSION 0.1 LANGUAGES C CXX)

 set(CMAKE_CXX_STANDARD 23)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)
 set(CMAKE_CXX_EXTENSIONS OFF)

# recommended compiler warnings
# https://github.com/cpp-best-practices/cppbestpractices/blob/master/02-Use_the_Tools_Available.md#compilers
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    # use this warnings
    add_compile_options(/permissive-)
    add_compile_options(/W4)
    add_compile_options(/w14640)
    # consider these
    add_compile_options(/w14242)
    add_compile_options(/w14254)
    add_compile_options(/w14263)
    add_compile_options(/w14265)
    add_compile_options(/w14287)
    add_compile_options(/we4289)
    add_compile_options(/w14296)
    add_compile_options(/w14311)
    add_compile_options(/w14545)
    add_compile_options(/w14546)
    add_compile_options(/w14547)
    add_compile_options(/w14549)
    add_compile_options(/w14555)
    add_compile_options(/w14619)
    add_compile_options(/w14826)
    add_compile_options(/w14905)
    add_compile_options(/w14906)
    add_compile_options(/w14928)
else()
    # use this warnings
    add_compile_options(-Wall)
    add_compile_options(-Wextra)
    add_compile_options(-Wshadow)
    add_compile_options(-Wnon-virtual-dtor)
    add_compile_options(-pedantic)
    # consider these
    add_compile_options(-Wold-style-cast)
    add_compile_options(-Wcast-align)
    add_compile_options(-Wunused)
    add_compile_options(-Woverloaded-virtual)
    add_compile_options(-Wpedantic)
    add_compile_options(-Wconversion)
    add_compile_options(-Wsign-conversion)
    add_compile_options(-Wmisleading-indentation)
    add_compile_options(-Wduplicated-cond)
    add_compile_options(-Wduplicated-branches)
    add_compile_options(-Wlogical-op)
    add_compile_options(-Wnull-dereference)
    add_compile_options(-Wuseless-cast)
    add_compile_options(-Wdouble-promotion)
    add_compile_options(-Wformat=2)
    # only special branch of Clang currently
    #add_compile_options(-Wlifetime)
    add_compile_options(-Wimplicit-fallthrough)
    # can be too noisy
    add_compile_options(-Weffc++)
endif()

find_package(Boost 1.86.0 REQUIRED COMPONENTS program_options)
# include_directories("${Boost_INCLUDE_DIRS}")
find_package(Catch2 3 REQUIRED)

add_subdirectory(src)

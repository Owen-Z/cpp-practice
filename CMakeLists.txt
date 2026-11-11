cmake_minimum_required(VERSION 3.25)
project(cpp_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

option(PRACTICE_SANITIZE "Enable AddressSanitizer + UBSan in Debug builds" ON)

# Shared warnings / sanitizer flags, applied to every target via this interface library.
add_library(practice_options INTERFACE)
target_compile_options(practice_options INTERFACE
  -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion
  -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wnull-dereference)
if(PRACTICE_SANITIZE)
  set(_san -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=all)
  target_compile_options(practice_options INTERFACE $<$<CONFIG:Debug>:${_san}>)
  target_link_options(practice_options INTERFACE $<$<CONFIG:Debug>:${_san}>)
endif()

# Reusable code: headers in include/practice, sources in src/.
file(GLOB_RECURSE PRACTICE_SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(practice ${PRACTICE_SOURCES})
target_include_directories(practice PUBLIC include)
target_link_libraries(practice PUBLIC practice_options)

# Every apps/<name>.cpp becomes its own executable <name>.
file(GLOB APP_SOURCES CONFIGURE_DEPENDS apps/*.cpp)
foreach(app_src IN LISTS APP_SOURCES)
  get_filename_component(app_name ${app_src} NAME_WE)
  add_executable(${app_name} ${app_src})
  target_link_libraries(${app_name} PRIVATE practice)
endforeach()

# Unit tests: every tests/*.cpp is compiled into one GoogleTest binary.
include(CTest)
if(BUILD_TESTING)
  find_package(GTest REQUIRED)
  file(GLOB TEST_SOURCES CONFIGURE_DEPENDS tests/*.cpp)
  add_executable(practice_tests ${TEST_SOURCES})
  target_link_libraries(practice_tests PRIVATE practice GTest::gtest_main GTest::gmock)
  include(GoogleTest)
  gtest_discover_tests(practice_tests)
endif()

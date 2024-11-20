cmake_minimum_required (VERSION 3.14)

project (BCU ASM C CXX)

option(USE_ETHERNET "Enable ethernet peripheral" OFF)
option(TARGET_NUCLEO "Targets the STM32H723 Nucleo development board" OFF)

message(STATUS "${PROJECT_NAME} Ethernet: ${USE_ETHERNET}")
message(STATUS "${PROJECT_NAME} Nucleo:   ${TARGET_NUCLEO}")

if (PROJECT_IS_TOP_LEVEL AND NOT CMAKE_CROSSCOMPILING)
  include(FetchContent)
  option(BUILD_GMOCK OFF)
  option(INSTALL_GTEST OFF)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
  )
  FetchContent_MakeAvailable(googletest)
  add_library(GTest::GTest INTERFACE IMPORTED)
  target_link_libraries(GTest::GTest INTERFACE gtest_main)
endif()

add_subdirectory(BCU-Master-H10)
set(USE_ETHERNET OFF)
add_subdirectory(BCU-Slave-H10)

if (PROJECT_IS_TOP_LEVEL)
    # Create symlink to compile_commands.json for IDE to pick it up
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_CURRENT_LIST_DIR}/compile_commands.json
    )
endif()
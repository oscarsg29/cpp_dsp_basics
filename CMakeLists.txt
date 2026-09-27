cmake_minimum_required(VERSION 3.22)

if(DSP_PLATFORM STREQUAL "esp32")
    if(NOT DEFINED ENV{IDF_PATH})
        message(FATAL_ERROR "Activate ESP-IDF before configuring the esp32 preset (IDF_PATH is missing)")
    endif()
    set(EXTRA_COMPONENT_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/platform/esp32/main")
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(dsp_tests_esp32)
else()
    project(cpp_dsp_basics LANGUAGES CXX)

    add_library(dsp INTERFACE)
    target_include_directories(dsp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_compile_features(dsp INTERFACE cxx_std_17)

    add_library(dsp_tests_core STATIC tests/test_suite.cpp)
    target_link_libraries(dsp_tests_core PUBLIC dsp)

    if(NOT CMAKE_CROSSCOMPILING)
        add_executable(dsp_tests tests/native_main.cpp)
        target_link_libraries(dsp_tests PRIVATE dsp_tests_core)

        enable_testing()
        add_test(NAME dsp_tests COMMAND dsp_tests)
    endif()
endif()

cmake_minimum_required(VERSION 3.10)

project(ImageEditor)

set(CMAKE_CXX_STANDARD 17)
# Set policy CMP0074 to NEW to respect *_ROOT variables like GTest_ROOT
cmake_policy(SET CMP0074 NEW)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add image processing libs
add_library(blur src/blur.cpp)
add_library(rotate src/rotate.cpp)
add_library(sobel src/sobel.cpp)

# Find OpenCV
find_package(OpenCV REQUIRED)
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found!")
endif()
include_directories(${OpenCV_INCLUDE_DIRS})

# Add demo executable that uses all filters
add_executable(demo_all_filters src/demo_all_filters.cpp)
target_link_libraries(demo_all_filters blur rotate sobel ${OpenCV_LIBS})

# Enable testing
enable_testing()
include(CTest)

# Find GoogleTest
find_package(GTest QUIET)

if(GTest_FOUND)
    message(STATUS "Using system-installed GoogleTest")
    include_directories(${GTEST_INCLUDE_DIRS})

    # Add tests - pass cases
    add_executable(test_blur tests/test_blur.cpp)
    target_link_libraries(test_blur blur ${OpenCV_LIBS} GTest::gtest GTest::gtest_main)
    add_test(NAME test_blur COMMAND test_blur)

    add_executable(test_rotate tests/test_rotate.cpp)
    target_link_libraries(test_rotate rotate ${OpenCV_LIBS} GTest::gtest GTest::gtest_main)
    add_test(NAME test_rotate COMMAND test_rotate)

    add_executable(test_sobel tests/test_sobel.cpp)
    target_link_libraries(test_sobel sobel ${OpenCV_LIBS} GTest::gtest GTest::gtest_main)
    add_test(NAME test_sobel COMMAND test_sobel)

    add_executable(test_4_rotate tests/test_4_rotate.cpp)
    target_link_libraries(test_4_rotate rotate ${OpenCV_LIBS} GTest::gtest GTest::gtest_main)
    add_test(NAME test_4_rotate COMMAND test_4_rotate)

    add_executable(test_blur_mean tests/test_blur_mean.cpp)
    target_link_libraries(test_blur_mean blur ${OpenCV_LIBS} GTest::gtest GTest::gtest_main)
    add_test(NAME test_blur_mean COMMAND test_blur_mean)

    add_executable(test_blur_wrng_input tests/test_blur_wrng_input.cpp)
    target_link_libraries(test_blur_wrng_input blur ${OpenCV_LIBS} GTest::gtest GTest::gtest_main)
    add_test(NAME test_blur_wrng_input COMMAND test_blur_wrng_input)

    # Add tests - fail cases
    add_executable(test_blur_fail tests/test_blur_fail.cpp)
    target_link_libraries(test_blur_fail blur ${OpenCV_LIBS} GTest::gtest GTest::gtest_main)
    add_test(NAME test_blur_fail COMMAND test_blur_fail)

    add_executable(test_rotate_fail tests/test_rotate_fail.cpp)
    target_link_libraries(test_rotate_fail rotate ${OpenCV_LIBS} GTest::gtest GTest::gtest_main)
    add_test(NAME test_rotate_fail COMMAND test_rotate_fail)

    add_executable(test_sobel_fail tests/test_sobel_fail.cpp)
    target_link_libraries(test_sobel_fail sobel ${OpenCV_LIBS} GTest::gtest GTest::gtest_main)
    add_test(NAME test_sobel_fail COMMAND test_sobel_fail)

elseif(WIN32)
    message(STATUS "GoogleTest not found via find_package. Using manual Windows paths.")

    set(GTEST_INCLUDE_DIR "C:/Users/7000041455/googletest-1.17.0/googletest/include")
    set(GTEST_LIB_DIR "C:/Users/7000041455/googletest-1.17.0/build/lib/Release")

    include_directories(${GTEST_INCLUDE_DIR})

    # Add tests - pass cases
    add_executable(test_blur tests/test_blur.cpp)
    target_link_libraries(test_blur blur ${OpenCV_LIBS}
        "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib"
    )
    add_test(NAME test_blur COMMAND test_blur)

    add_executable(test_rotate tests/test_rotate.cpp)
    target_link_libraries(test_rotate rotate ${OpenCV_LIBS}
        "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib"
    )
    add_test(NAME test_rotate COMMAND test_rotate)

    add_executable(test_sobel tests/test_sobel.cpp)
    target_link_libraries(test_sobel sobel ${OpenCV_LIBS}
        "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib"
    )
    add_test(NAME test_sobel COMMAND test_sobel)

    add_executable(test_4_rotate tests/test_4_rotate.cpp)
    target_link_libraries(test_4_rotate rotate ${OpenCV_LIBS}
        "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib"
    )
    add_test(NAME test_4_rotate COMMAND test_4_rotate)

    add_executable(test_blur_mean tests/test_blur_mean.cpp)
    target_link_libraries(test_blur_mean blur ${OpenCV_LIBS}
        "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib"
    )
    add_test(NAME test_blur_mean COMMAND test_blur_mean)

    add_executable(test_blur_wrng_input tests/test_blur_wrng_input.cpp)
    target_link_libraries(test_blur_wrng_input blur ${OpenCV_LIBS}
        "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib"
    )
    add_test(NAME test_blur_wrng_input COMMAND test_blur_wrng_input)

    # Add tests - fail cases
    add_executable(test_blur_fail tests/test_blur_fail.cpp)
    target_link_libraries(test_blur_fail blur ${OpenCV_LIBS}
        "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib"
    )
    add_test(NAME test_blur_fail COMMAND test_blur_fail)

    add_executable(test_rotate_fail tests/test_rotate_fail.cpp)
    target_link_libraries(test_rotate_fail rotate ${OpenCV_LIBS}
        "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib"
    )
    add_test(NAME test_rotate_fail COMMAND test_rotate_fail)

    add_executable(test_sobel_fail tests/test_sobel_fail.cpp)
    target_link_libraries(test_sobel_fail sobel ${OpenCV_LIBS}
        "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib"
    )
    add_test(NAME test_sobel_fail COMMAND test_sobel_fail)

else()
    message(FATAL_ERROR "GoogleTest not found. On Linux, install it with: sudo apt install libgtest-dev")
endif()



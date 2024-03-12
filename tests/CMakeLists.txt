include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
  EXCLUDE_FROM_ALL    # requires cmake 3.28 to work correctly
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(easyhash_test
  fnv1a_test.cpp
)

target_link_libraries(easyhash_test
    PRIVATE
        gtest_main
        easyhash::easyhash
)

add_test(NAME easyhash_test COMMAND easyhash_test)

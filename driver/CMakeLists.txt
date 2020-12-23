find_package(PkgConfig REQUIRED)

set(DIR ${CMAKE_CURRENT_LIST_DIR})

add_executable(driver "")

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
target_compile_options(driver PRIVATE -pedantic -Wall -Wmost -Wextra)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(driver PRIVATE -pedantic -Wall -Wextra)
endif()

target_sources(driver
    PRIVATE
    "${DIR}/driver.cpp"
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(driver PRIVATE Threads::Threads swar)
target_include_directories(driver PRIVATE "${swar_SOURCE_DIR}/include")
target_include_directories(driver PUBLIC "${swar_SOURCE_DIR}/controllers")

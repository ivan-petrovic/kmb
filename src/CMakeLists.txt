cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 11)

project(KMB VERSION 0.2 LANGUAGES CXX)

# Bring the headers into the project
include_directories(../include)

# Can manually add the sources using the set command as follows:
# set(SOURCES src/mainapp.cpp src/Student.cpp)

# However, the file(GLOB...) allows for wildcard additions:
# file(GLOB SOURCES "src/*.cpp")
file(GLOB E_CORE_SRC "engine/core/*.cpp")
file(GLOB E_STAT_SRC "engine/stat/*.cpp")
file(GLOB E_SRC "engine/*.cpp")
file(GLOB COMMAND_SRC "command/*.cpp")
file(GLOB EXPERIMENT_SRC "experiment/*.cpp")

add_executable(kmb
    main.cpp
    ${E_CORE_SRC}
    ${E_STAT_SRC}
    ${E_SRC}
    ${COMMAND_SRC}
    ${EXPERIMENT_SRC}
)

add_executable(test_shuffle ../tests/shufflet.cpp)
add_executable(test_constants ../tests/constantst.cpp ${E_SRC})
add_executable(test_set4 ../tests/set_of_4s_t.cpp ${E_CORE_SRC} ${E_SRC})
add_executable(test_all7 ../tests/all7s_t.cpp ${E_CORE_SRC} ${E_SRC})

cmake_minimum_required(VERSION 3.16)
project(ExecutionRL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Include paths ===
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/agents
        ${CMAKE_SOURCE_DIR}/include/core
        ${CMAKE_SOURCE_DIR}/include/env
        ${CMAKE_SOURCE_DIR}/include/utils
)

# === Source files ===
set(LIB_SOURCES
        include/agents/QLearningAgent.cpp
        include/core/ExecutionSimulator.cpp
        include/env/MarketEnvironment.cpp
        include/utils/Logger.cpp
        include/utils/MathUtils.cpp)

add_library(executionrl_lib ${LIB_SOURCES})
target_include_directories(executionrl_lib PUBLIC include)
target_compile_definitions(executionrl_lib PRIVATE DATA_PATH="${CMAKE_SOURCE_DIR}/data/price_series.csv")

add_executable(ExecutionRL src/main.cpp)
target_link_libraries(ExecutionRL PRIVATE executionrl_lib)
target_include_directories(ExecutionRL PRIVATE include)

# === Tests ===
enable_testing()

add_executable(test_agent tests/test_agent.cpp)
add_executable(test_env tests/test_env.cpp)
add_executable(test_simulation tests/test_simulation.cpp)

target_link_libraries(test_agent PRIVATE executionrl_lib)
target_link_libraries(test_env PRIVATE executionrl_lib)
target_link_libraries(test_simulation PRIVATE executionrl_lib)
target_include_directories(test_agent PRIVATE include)
target_include_directories(test_env PRIVATE include)
target_include_directories(test_simulation PRIVATE include)

add_test(NAME AgentTest COMMAND test_agent)
add_test(NAME EnvTest COMMAND test_env)
add_test(NAME SimulationTest COMMAND test_simulation)
set_tests_properties(AgentTest EnvTest SimulationTest
    PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

#include "../include/core/ExecutionSimulator.hpp"
#include "../include/env/MarketEnvironment.hpp"
#include "../include/agents/QLearningAgent.hpp"
#include "../include/config.hpp"
#include <iostream>

int main() {
    MarketEnvironment env;
    QLearningAgent agent(ALPHA, GAMMA, EPSILON);
    ExecutionSimulator sim(env, agent);

    sim.run();

    std::cout << "test_simulation passed.\n";
    return 0;
}

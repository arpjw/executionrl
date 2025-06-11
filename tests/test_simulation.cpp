#include "core/ExecutionSimulator.hpp"
#include "env/MarketEnvironment.hpp"
#include "agents/QLearningAgent.hpp"
#include "config.hpp"
#include <iostream>

int main() {
    MarketEnvironment env;
    QLearningAgent agent(ALPHA, GAMMA, EPSILON);
    ExecutionSimulator sim(env, agent);

    sim.run();

    std::cout << "test_simulation passed.\n";
    return 0;
}

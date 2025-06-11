#include "include/core/ExecutionSimulator.hpp"
#include "include/env/MarketEnvironment.hpp"
#include "include/agents/QLearningAgent.hpp"

int main() {
    MarketEnvironment env;
    QLearningAgent agent(0.1, 0.9, 0.1); // alpha, gamma, epsilon

    ExecutionSimulator simulator(env, agent);
    simulator.run(1000); // Run for 1000 episodes

    return 0;
}

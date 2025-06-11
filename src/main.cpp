#include "core/ExecutionSimulator.hpp"
#include "env/MarketEnvironment.hpp"
#include "agents/QLearningAgent.hpp"

int main() {
    MarketEnvironment env;
    QLearningAgent agent(0.1, 0.9, 0.1); // alpha, gamma, epsilon

    ExecutionSimulator simulator(env, agent);
    simulator.run();

    return 0;
}

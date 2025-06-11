#include "../include/agents/QLearningAgent.hpp"
#include <cassert>
#include <iostream>

int main() {
    QLearningAgent agent(0.1, 0.9, 0.1);
    std::vector<double> state = {100.0, 0.0, 0.0};
    int action = agent.chooseAction(state);
    assert(action >= 0 && action <= 2);

    std::vector<double> nextState = {101.0, 1.0, 0.5};
    agent.update(state, action, 1.0, nextState);

    std::cout << "test_agent passed.\n";
    return 0;
}

#pragma once

#include "env/MarketEnvironment.hpp"
#include "agents/QLearningAgent.hpp"
#include "utils/Logger.hpp"
#include <vector>

class ExecutionSimulator {
public:
    ExecutionSimulator(MarketEnvironment& env, QLearningAgent& agent);
    void run(int episodes = 1);

private:
    MarketEnvironment& env;
    QLearningAgent& agent;
};

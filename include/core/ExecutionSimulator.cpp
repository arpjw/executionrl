#include "core/ExecutionSimulator.hpp"

ExecutionSimulator::ExecutionSimulator(MarketEnvironment& env, QLearningAgent& agent)
    : env(env), agent(agent) {}

void ExecutionSimulator::run() {
    env.reset();
    while (!env.isDone()) {
        auto state = env.getState();
        int action = agent.chooseAction(state);
        double reward = env.step(action);
        auto nextState = env.getState();
        agent.update(state, action, reward, nextState);
    }
}

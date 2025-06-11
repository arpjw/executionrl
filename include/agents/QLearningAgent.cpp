#include "QLearningAgent.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>
#include <algorithm>

QLearningAgent::QLearningAgent(double alpha, double gamma, double epsilon)
    : alpha(alpha), gamma(gamma), epsilon(epsilon) {}

int QLearningAgent::chooseAction(const std::vector<double>& state) {
    std::string key = serializeState(state);
    ensureStateExists(key);

    if ((double) rand() / RAND_MAX < epsilon) {
        return rand() % qTable[key].size(); // Explore
    } else {
        // Exploit: choose action with max Q-value
        auto& actions = qTable[key];
        return std::distance(actions.begin(), std::max_element(actions.begin(), actions.end()));
    }
}

void QLearningAgent::update(const std::vector<double>& state, int action, double reward, const std::vector<double>& nextState) {
    std::string key = serializeState(state);
    std::string nextKey = serializeState(nextState);
    ensureStateExists(key);
    ensureStateExists(nextKey);

    double maxNextQ = *std::max_element(qTable[nextKey].begin(), qTable[nextKey].end());
    double currentQ = qTable[key][action];
    qTable[key][action] += alpha * (reward + gamma * maxNextQ - currentQ);
}

std::string QLearningAgent::serializeState(const std::vector<double>& state) const {
    std::string result;
    for (double val : state) {
        result += std::to_string(std::round(val * 100.0) / 100.0) + ",";
    }
    return result;
}

void QLearningAgent::ensureStateExists(const std::string& key) {
    if (qTable.find(key) == qTable.end()) {
        qTable[key] = std::vector<double>(3, 0.0); // Assuming 3 actions: Buy, Hold, Sell
    }
}

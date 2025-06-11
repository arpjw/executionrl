#pragma once
#include <vector>
#include <unordered_map>
#include <string>

class QLearningAgent {
public:
    QLearningAgent(double alpha, double gamma, double epsilon);

    int chooseAction(const std::vector<double>& state);
    void update(const std::vector<double>& state, int action, double reward, const std::vector<double>& nextState);

private:
    double alpha;   // learning rate
    double gamma;   // discount factor
    double epsilon; // exploration rate

    std::unordered_map<std::string, std::vector<double>> qTable;

    std::string serializeState(const std::vector<double>& state) const;
    void ensureStateExists(const std::string& key);
};

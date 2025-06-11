#include "MarketEnvironment.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

MarketEnvironment::MarketEnvironment() {
    loadMarketData();
    reset();
}

void MarketEnvironment::reset() {
    currentStep = 0;
    position = 0.0;
    pnl = 0.0;
}

std::vector<double> MarketEnvironment::getState() const {
    if (currentStep < prices.size()) {
        return {prices[currentStep], position, pnl};
    }
    return {0.0, position, pnl};
}

double MarketEnvironment::step(int action) {
    if (isDone()) return 0.0;

    double price = prices[currentStep];
    double reward = calculateReward(action);

    if (action == 1) position = 1.0;     // buy
    else if (action == 2) position = -1.0; // sell

    pnl += reward;
    currentStep++;
    return reward;
}

bool MarketEnvironment::isDone() const {
    return currentStep >= prices.size();
}

void MarketEnvironment::loadMarketData() {
    std::ifstream file(DATA_PATH);
    if (!file.is_open()) {
        file.open("../data/price_series.csv");
    }
    std::string line;

    prices.clear();

    // Skip header line if present
    if (std::getline(file, line)) {
        if (line.find("price") == std::string::npos) {
            std::stringstream ss(line);
            std::string timestamp, priceStr;
            if (std::getline(ss, timestamp, ',') && std::getline(ss, priceStr, ',')) {
                prices.push_back(std::stod(priceStr));
            }
        }
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string timestamp, priceStr;
        if (std::getline(ss, timestamp, ',') && std::getline(ss, priceStr, ',')) {
            try {
                prices.push_back(std::stod(priceStr));
            } catch (const std::exception& e) {
                std::cerr << "Invalid price value: " << priceStr << "\n";
            }
        }
    }

    if (prices.empty()) {
        std::cerr << "Warning: No price data loaded.\n";
    }
}

double MarketEnvironment::calculateReward(int action) {
    if (currentStep == 0 || currentStep >= prices.size()) return 0.0;

    double priceChange = prices[currentStep] - prices[currentStep - 1];
    return position * priceChange;
}

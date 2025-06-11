#ifndef MARKET_ENVIRONMENT_HPP
#define MARKET_ENVIRONMENT_HPP

#include <vector>
#include <string>

class MarketEnvironment {
public:
    MarketEnvironment();
    void reset();
    std::vector<double> getState() const;
    double step(int action); // 0 = hold, 1 = buy, 2 = sell
    bool isDone() const;

private:
    std::vector<double> prices;
    size_t currentStep;
    double position; // +1 = long, -1 = short, 0 = flat
    double pnl;

    void loadMarketData();
    double calculateReward(int action);
};

#endif // MARKET_ENVIRONMENT_HPP

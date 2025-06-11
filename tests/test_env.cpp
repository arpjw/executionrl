#include "env/MarketEnvironment.hpp"
#include <cassert>
#include <iostream>

int main() {
    MarketEnvironment env;
    env.reset();
    auto state = env.getState();
    assert(state.size() == 3);

    double reward = env.step(1);  // buy
    assert(!env.isDone());

    std::cout << "test_env passed.\n";
    return 0;
}

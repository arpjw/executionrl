#include "utils/MathUtils.hpp"

namespace MathUtils {
    double mean(const std::vector<double>& data) {
        if (data.empty()) return 0.0;
        double sum = 0.0;
        for (double d : data) sum += d;
        return sum / data.size();
    }
}

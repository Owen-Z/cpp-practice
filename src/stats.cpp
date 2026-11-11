#include "practice/stats.hpp"

#include <numeric>

namespace practice {

void RunningStats::push(double x) noexcept {
    ++n_;
    const double delta = x - mean_;
    mean_ += delta / static_cast<double>(n_);
    m2_ += delta * (x - mean_);
}

double RunningStats::variance() const noexcept {
    return n_ < 2 ? 0.0 : m2_ / static_cast<double>(n_ - 1);
}

double mean(std::span<const double> xs) noexcept {
    if (xs.empty()) {
        return 0.0;
    }
    return std::accumulate(xs.begin(), xs.end(), 0.0) / static_cast<double>(xs.size());
}

}  // namespace practice

#pragma once

#include <cstddef>
#include <span>

namespace practice {

// Online mean/variance (Welford's algorithm): O(1) per update, numerically stable.
class RunningStats {
public:
    void push(double x) noexcept;

    [[nodiscard]] std::size_t count() const noexcept { return n_; }
    [[nodiscard]] double mean() const noexcept { return mean_; }
    [[nodiscard]] double variance() const noexcept;  // sample variance, 0 if n < 2

private:
    std::size_t n_ = 0;
    double mean_ = 0.0;
    double m2_ = 0.0;
};

// Arithmetic mean of a range; 0 for an empty range.
[[nodiscard]] double mean(std::span<const double> xs) noexcept;

}  // namespace practice

#include <gtest/gtest.h>

#include <vector>

#include "practice/stats.hpp"

TEST(RunningStats, EmptyIsZero) {
    practice::RunningStats s;
    EXPECT_EQ(s.count(), 0u);
    EXPECT_DOUBLE_EQ(s.mean(), 0.0);
    EXPECT_DOUBLE_EQ(s.variance(), 0.0);
}

TEST(RunningStats, MatchesTwoPassFormula) {
    const std::vector<double> xs{2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
    practice::RunningStats s;
    for (double x : xs) {
        s.push(x);
    }
    EXPECT_EQ(s.count(), xs.size());
    EXPECT_DOUBLE_EQ(s.mean(), 5.0);
    EXPECT_NEAR(s.variance(), 32.0 / 7.0, 1e-12);
}

TEST(Mean, EmptyAndNonEmpty) {
    EXPECT_DOUBLE_EQ(practice::mean({}), 0.0);
    const std::vector<double> xs{1.0, 2.0, 3.0};
    EXPECT_DOUBLE_EQ(practice::mean(xs), 2.0);
}

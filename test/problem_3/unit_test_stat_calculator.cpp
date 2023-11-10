/*
 * DO NOT MAKE ANY CHANGES
 */

#include "unit_test_stat_calculator.h"
#include "problem_3/stat_calculator.h"
#include "problem_3/list/array_list.h"
#include "problem_1/list/linked_list.h"

TEST(problem_3, mean) {
    std::vector<TestCaseMeanValue> test_cases = {
            TestCaseMeanValue({}, 0),
            TestCaseMeanValue({0}, 0),
            TestCaseMeanValue({0, 1}, 0.5),
            TestCaseMeanValue({1, 0}, 0.5),
            TestCaseMeanValue({-1, 1}, 0),
            TestCaseMeanValue({-1, 0, 1}, 0),
            TestCaseMeanValue({-1, 1, 2}, 2.0 / 3),
            TestCaseMeanValue({0, 2, 1}, 1),
            TestCaseMeanValue({-1, 6, 2}, 7.0 / 3),
    };

    for (int i = 0; i < test_cases.size(); i++) {
        auto &test_case = test_cases[i];
        ArrayList<float> data(test_case.data);
        float actual = StatCalculator::mean(data);
        ASSERT_FLOAT_EQ(test_case.expect, actual) << case_id(i);
    }
}

TEST(problem_3, step_percentile) {
    std::vector<TestCasePercentiles> test_cases = {
            TestCasePercentiles(
                    {8.8, 1.5, 2, 10.2, 10.3, 10.4}, 20,
                    {
                            {0,   1.5},
                            {20,  2},
                            {40,  8.8},
                            {60,  10.2},
                            {80,  10.3},
                            {100, 10.4},
                    }),
            TestCasePercentiles(
                    {9, 10, 2, 10, -5, -99}, 30,
                    {
                            {0,  -99},
                            {30, -1.5},
                            {60, 9},
                            {90, 10},
                    }),
            TestCasePercentiles(
                    {0, 2, 4}, 5,
                    {
                            {0,   0},
                            {5,   0.2},
                            {10,  0.4},
                            {15,  0.6},
                            {20,  0.8},
                            {25,  1},
                            {30,  1.2},
                            {35,  1.4},
                            {40,  1.6},
                            {45,  1.8},
                            {50,  2},
                            {55,  2.2},
                            {60,  2.4},
                            {65,  2.6},
                            {70,  2.8},
                            {75,  3},
                            {80,  3.2},
                            {85,  3.4},
                            {90,  3.6},
                            {95,  3.8},
                            {100, 4},
                    }),
            TestCasePercentiles(
                    {9, 8, 1, 3, 90, 99}, 5,
                    {
                            {0,   1},
                            {5,   1.5},
                            {10,  2},
                            {15,  2.5},
                            {20,  3},
                            {25,  4.25},
                            {30,  5.5},
                            {35,  6.75},
                            {40,  8},
                            {45,  8.25},
                            {50,  8.5},
                            {55,  8.75},
                            {60,  9},
                            {65,  29.25},
                            {70,  49.5},
                            {75,  69.75},
                            {80,  90},
                            {85,  92.25},
                            {90,  94.5},
                            {95,  96.75},
                            {100, 99},
                    }),
    };

    for (int i = 0; i < test_cases.size(); i++) {
        auto &test_case = test_cases[i];
        ArrayMap<int, float> actual_percentiles(test_case.expect.size());
        ArrayList<float> input(test_case.input);

        StatCalculator::percentiles(input, test_case.step, actual_percentiles);

        LinkedList<int> keys;
        actual_percentiles.key_set(keys);
        ASSERT_TRUE(keys.size() > 0) << case_id(i);

        for (int j = 0; j < keys.size(); j++) {
            float expect;
            ASSERT_TRUE(test_case.expect.get(keys[j], expect)) << case_id(i, j);
            float actual;
            ASSERT_TRUE(actual_percentiles.get(keys[j], actual)) << case_id(i, j);
            ASSERT_FLOAT_EQ(expect, actual) << case_id(i, j);
        }
    }
}
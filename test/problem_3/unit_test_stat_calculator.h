/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"

#include "problem_2/array_map.h"

#include "../common/util.h"

typedef std::vector<std::pair<int, float>> list_of_float_kv;

class TestCaseMeanValue {
public:
    std::vector<float> data;

    float expect;

    TestCaseMeanValue(const std::vector<float> &data, float expect) : data(data), expect(expect) {}
};

class TestCasePercentiles {
public:
    std::vector<float> input;
    int step;
    ArrayMap<int, float> expect;

    TestCasePercentiles(const std::vector<float> &data, int percentile_step,
                        const list_of_float_kv &result) : input(data),
                                                          step(percentile_step),
                                                          expect(result) {} // this needs ArrayMap to have a functioning copy constructor
};
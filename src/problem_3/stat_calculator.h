/*
 * DO NOT MAKE ANY CHANGES
 */

#pragma once

#include "../common/list.h"
#include "../problem_2/array_map.h"
#include <cmath>

class StatCalculator {
private:
    static void sort(List<float> &data);

    static void swap(List<float> &data, size_t i, size_t j);

public:
    static float mean(const List<float> &data);

    static void percentiles(List<float> &data, int percentile_target_step, Map<int, float> &result_map);
};
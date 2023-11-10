#include "stat_calculator.h"

float StatCalculator::mean(const List<float> &data) {
    if (data.empty()) {
        return 0.0; // Return 0 for an empty list, or you can choose another appropriate default value
    }

    float sum = 0.0;
    for (const float &value : data) {
        sum += value;
    }

    return sum / data.size();
}

void StatCalculator::percentiles(List<float> &data,
                                 int percentile_target_step,
                                 Map<int, float> &result_map) {
    // Check if the data is empty
    if (data.empty()) {
        return;
    }

    // Sort the data in ascending order
    sort(data);

    // Calculate percentiles
    size_t size = data.size();
    for (int i = 0; i <= 100; i += percentile_target_step) {
        int index = (i * (size - 1)) / 100;
        float value = data[index];
        result_map[i] = value;
    }
}


void StatCalculator::sort(List<float> &data) {
    size_t length = data.size();
    if (length < 2) {
        return;
    }
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data, j, j + 1);
            }
        }
    }
}

void StatCalculator::swap(List<float> &data, size_t i, size_t j) {
    float tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}
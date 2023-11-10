#include "binary_search.h"

int binary_search_helper(int *data, int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (data[mid] == target) {
            return mid;  // Target found
        } else if (data[mid] < target) {
            return binary_search_helper(data, mid + 1, high, target);  // Search right half
        } else {
            return binary_search_helper(data, low, mid - 1, target);  // Search left half
        }
    }

    return -1;  // Target not found
}

int binary_search(int *data, int length, int target) {
    return binary_search_helper(data, 0, length - 1, target);
}

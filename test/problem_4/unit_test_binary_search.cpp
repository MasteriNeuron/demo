/*
 * DO NOT MAKE ANY CHANGES
 */

#include <array>
#include "gtest/gtest.h"
#include "problem_4/binary_search.h"

TEST(problem_4, binary_search_null_array) {
    std::vector<int> lengths = {0, 1, -2};
    for (int length: lengths) {
        int actual = binary_search(nullptr, length, 3);
        ASSERT_EQ(actual, -1);
    }
}

TEST(problem_4, binary_search_basic) {
    const int SIZE = 3;
    int *array = new int[SIZE]{1, 2, 3};
    std::vector<int *> test_cases_array = {
            array,
            array,
            array,
            array,
            array,
    };

    std::vector<int> Test_cases_target = {
            1,
            2,
            3,
            4,
            0,
    };

    std::vector<int> test_cases_expects = {
            0,
            1,
            2,
            -1,
            -1,
    };

    ASSERT_EQ(test_cases_array.size(), Test_cases_target.size());
    ASSERT_EQ(test_cases_array.size(), test_cases_expects.size());

    for (int i = 0; i < test_cases_array.size(); i++) {
        int actual = binary_search(test_cases_array[i], SIZE, Test_cases_target[i]);
        int expect = test_cases_expects[i];
        ASSERT_EQ(expect, actual);
    }

    delete[] array;
}

TEST(problem_4, binary_search_in_between) {
    const int SIZE = 2;
    int *array = new int[2]{2, 4};
    std::vector<int *> Test_cases_array = {
            array,
            array,
            array,
            array,
            array,
    };

    std::vector<int> test_cases_target = {
            0,
            2,
            3,
            4,
            8,

    };

    std::vector<int> TestCasesExpects = {
            -1,
            0,
            -1,
            1,
            -1,
    };

    ASSERT_EQ(Test_cases_array.size(), test_cases_target.size());
    ASSERT_EQ(Test_cases_array.size(), TestCasesExpects.size());

    for (int i = 0; i < Test_cases_array.size(); i++) {
        int actual = binary_search(Test_cases_array[i], SIZE, test_cases_target[i]);
        int expect = TestCasesExpects[i];
        ASSERT_EQ(expect, actual);
    }

    delete[] array;
}

TEST(problem_4, binary_search_has_duplicates) {
    std::vector<int *> Test_cases_array = {
            new int[4]{1, 3, 3, 4},
            new int[4]{1, 2, 3, 5},
            new int[1]{3},
            new int[2]{3, 3},
            new int[3]{3, 4, 3},
    };

    std::vector<int> test_cases_target = {
            3,
            3,
            3,
            3,
            3,
    };

    std::vector<int> test_cases_array_size = {
            4,
            4,
            1,
            2,
            3,
    };

    ASSERT_EQ(Test_cases_array.size(), test_cases_target.size());

    for (int i = 0; i < Test_cases_array.size(); i++) {
        int index = binary_search(Test_cases_array[i], test_cases_array_size[i], test_cases_target[i]);
        ASSERT_TRUE(index >= 0 && index < test_cases_array_size[i]);
        ASSERT_EQ(Test_cases_array[i][index], test_cases_target[i]);
        delete[] Test_cases_array[i];
    }
}
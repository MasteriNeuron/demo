/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"

#include "list_printer.h"

template<typename T>
void linked_list_reverse_print() {
    const int SIZE = 100;
    MemoryPrinter printer;

    for (int i = 0; i < SIZE; i++) {
        const int test_size = i;
        std::vector<std::string> expect;
        LinkedList<T> list;

        // prepare the test
        for (int j = 0; j < test_size; j++) {
            list.push_back(T(j));
            expect.push_back(std::to_string(T(test_size - j - 1)));
            expect.emplace_back("\n");
        }

        // call the function
        list.reverse_print(printer);

        // validate result
        auto &actual = printer.get_output();
        ASSERT_EQ(expect, actual) << "case " + std::to_string(i) + " failed";

        // clear print buffer
        printer.clear();
    }
}
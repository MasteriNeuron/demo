#include "problem_1/list/linked_list.h"
#include "problem_1/stdout_printer.h"

/*
 * This file is run through memory check.
 * However, any changes in this file will be ignored for grading, EXCEPT its memory leak
 * Meaning, if there's memory leak from this file, there will be points penalty
 */


void problem_1();

int main() {
    problem_1();
}

void problem_1() {
    LinkedList<int> list_int;
    for (int i = 0; i < 10; i++) {
        list_int.push_back(i);
    }

    StdoutPrinter printer;
    list_int.reverse_print(printer);

    LinkedList<float> list_float;
    list_float.push_back(1.1);
    list_float.push_back(3.3);
    list_float.reverse_print(printer);
}
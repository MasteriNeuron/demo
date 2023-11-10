#include "problem_1/printer.h"
#include "problem_1/list/linked_list.h"

class MemoryPrinter : public Printer {
private:
    std::vector<std::string> output;
public:
    const std::vector<std::string> &get_output() const {
        return output;
    }

    void clear() {
        output.clear();
    }

    void print(std::string val) override {
        /*
         * TODO: homework
         */
          output.push_back(val);
    };
};
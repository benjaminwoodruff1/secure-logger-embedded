#include <cstdlib>
#include <cstring>
#include <iostream>
#include "template.h"
#include "template.hpp"
#include "template_config.h"

#define USAGE "Usage: <function> <a> <b>\nfunction must be one of: 'sum', 'divide'\n" \
              "a, b must be integers\n"

int main(int argc, char** argv) {
    std::cout << "Hello, world!" << std::endl;
    std::cout << "Version: " << TEMPLATE_VERSION_MAJOR << "."
              << TEMPLATE_VERSION_MINOR << "." << TEMPLATE_VERSION_PATCH
              << std::endl;

    // Only proceed if exactly two arguments are provided
    if (argc != 4) {
        std::cerr << USAGE;
        return 1;
    }

    Template foo;
    template_t bar;

    // Use atoi() to convert string to integer
    foo.a = atoi(argv[2]);
    foo.b = atoi(argv[3]);
    bar.a = atoi(argv[2]);
    bar.b = atoi(argv[3]);

    // Sum case
    if (!strcmp(argv[1], "sum")) {
        std::cout << "foo: a == " << foo.a << ", b == " << foo.b << ", a+b == "
                  << foo.sum() << std::endl;
        std::cout << "bar: a == " << bar.a << ", b == " << bar.b << ", a+b == "
                  << template_sum(bar) << std::endl;
    }

    // Divide case
    else if (!strcmp(argv[1], "divide")) {
        std::cout << "foo: a == " << foo.a << ", b == " << foo.b << ", a/b == "
                  << foo.divide() << std::endl;
        std::cout << "bar: a == " << bar.a << ", b == " << bar.b << ", a/b == "
                  << template_divide(bar) << std::endl;
    }

    // Unknown operation case
    else {
        std::cerr << "Unknown operation '" << argv[1] << "'" << std::endl << USAGE;
        return 2;
    }

    return 0;
}

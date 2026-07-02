
#include <iostream>
#include "spryx/rnea.h"
#include "spryx/primitives.h"

int main() {
    std::cout << "Running RNEA tests..." << std::endl;
    const auto r = Rot3::identity();
    std::cout << r.to_string() << std::endl;
    return 0;
}

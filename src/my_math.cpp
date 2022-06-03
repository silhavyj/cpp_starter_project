#include "my_math.h"

namespace my_math {

    int add(int x, int y) {
        int z = x + y;
        return z < 0 ? (-z) : z;
    }

    int sub(int x, int y) {
        return x - y;
    }

    int mult(int x, int y) {
        return x * y;
    }
}
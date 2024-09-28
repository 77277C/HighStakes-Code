#include "console.hpp"

#define ASSERT(expr) \
    if (!(expr)) { \
        std::ostringstream oss; \
        oss << "Assertion failed: " << #expr; \
        console.println(oss.str()); \
    }
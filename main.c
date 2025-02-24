#include "functions.h"
#include <stdio.h>

int main() {
    init_cache();

    original_provider = fibonacci;
    fibonacci_pointer = cache;

    long num          = 10;
    printf("Fibonacci of %ld is %lld\n", num, (*fibonacci_pointer)(num));

    return 0;
}

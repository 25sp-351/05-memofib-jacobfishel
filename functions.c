#include "functions.h"

long results[100];

long_long_func_ptr original_provider;
long_long_func_ptr fibonacci_pointer;

long long fibonacci(long num) {
    if (num <= 1)
        return num;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

long long cache(long val) {
    if (val < 0 || val >= 100)
        return (*original_provider)(val);
    if (results[val] == NOT_PRESENT)
        results[val] = (*original_provider)(val);
    return results[val];
}

void init_cache() {
    for (int i = 0; i < 100; i++)
        results[i] = NOT_PRESENT;
}

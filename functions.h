#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef long long (*long_long_func_ptr)(long);

extern long results[100];

extern long_long_func_ptr original_provider;
extern long_long_func_ptr fibonacci_pointer;

#define NOT_PRESENT -1

long long fibonacci(long num);
long long cache(long val);
void init_cache(); 

#endif

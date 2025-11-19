Heap vs Stack Allocation Performance Test
Overview
------------------------------------------------------------

This C++ program demonstrates the difference in allocation performance between:

Heap allocation (new / delete)

Stack allocation (automatic local variables)

It measures the time taken to create and destroy multiple instances of a simple class MyObject for various numbers of objects.

Methodology
------------------------------------------------------------

Heap test (testHeap):

For each object, allocate on the heap using new MyObject().

Immediately delete it using delete.

Measure elapsed time with std::chrono::high_resolution_clock.

Stack test (testStack):

For each object, create it as a local variable (stack allocation).

Destructor is called automatically when the object goes out of scope.

Measure elapsed time similarly.

Compare elapsed times for different numbers of objects:
{ 10, 100, 1_000, 10_000, 100_000, 1_000_000, 10_000_000 }.
------------------------------------------------------------

Output Example

     Objects      Heap (ms)     Stack (ms)    Difference
------------------------------------------------------------
          10         0.0063         0.0002          31.50x
         100         0.0409         0.0011          37.18x
        1000         0.5703         0.0154          37.03x
       10000         3.2110         0.0854          37.60x
      100000        33.1820         0.8794          37.73x
     1000000       339.7068         8.6836          39.12x
    10000000      3857.7787        95.9852          40.19x

Observations:
------------------------------------------------------------

Stack allocation is significantly faster than heap allocation.

Heap allocation involves dynamic memory management, including bookkeeping, which adds overhead.

Stack allocation is almost free for simple objects because it just moves the stack pointer.

The difference grows with the number of objects, showing the cumulative cost of heap management.

Key Points
------------------------------------------------------------

Heap allocation (new)

Flexible, objects live beyond scope.

Slower due to dynamic memory management.

Stack allocation (local objects)

Fast, automatic cleanup.

Lifetime limited to scope.

No explicit delete needed.

Practical implication:
------------------------------------------------------------

For temporary objects with short lifetime, prefer stack allocation.

Use heap allocation only when objects must outlive the current scope or when the size is unknown at compile time.

How to Compile
------------------------------------------------------------

g++ -O2 -std=c++17 heap_vs_stack.cpp -o heap_vs_stack

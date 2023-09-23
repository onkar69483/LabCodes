# Data Structure Lab

Explore various data structures and sorting algorithms:

- [Search Algorithms](1_searchAlgo.c)
- [Bubble Sort](2_bubble_sort.c)
- [Selection Sort](3_selectionSort.c)
- [Quick Sort](4_quickSort.c)
- [Insertion Sort](5_insertionSort.c)
- [Merge Sort](6_mergeSort.c)
- [Time Complexities](6_timeComplexities.md)
- [Single Linked List Operations](7_SingleLinkedList.c)
- [Doubly Linked List Operations](8_doublyLinkedList.c)
- [Binary Search Tree](9_Tree.c)

## NOTES

The `malloc` function itself should work in offline compilers just as it does in online compilers because it's part of the standard C library. However, the issues you encountered were not related to the `malloc` function itself but rather how you were using it in conjunction with C++ code and structures.

Here's why `malloc` was problematic in your code:

1. **Mismatch of C and C++ Memory Management:** In C++, it's generally recommended to use `new` and `delete` for memory allocation and deallocation, respectively, for objects. The C++ language has constructors and destructors that may need to be called, and `new` and `delete` properly manage those aspects. On the other hand, `malloc` and `free` are C functions and do not call constructors and destructors for C++ objects. When you mix C++ code with C-style memory management, you risk encountering unexpected issues.

2. **Memory Leak Risk:** When you use `malloc` to allocate memory for C++ objects and don't use `free` to deallocate it (or `delete` to call destructors and deallocate), you create a memory leak. Memory leaks can lead to increased memory consumption over time, which can cause your program to run out of memory and crash.

3. **Undefined Behavior:** Mixing C-style memory management with C++ code can result in undefined behavior. This means that your program may behave inconsistently or unpredictably. Undefined behavior can manifest as program crashes, incorrect results, or other unexpected behavior.

In summary, it's not that `malloc` wasn't working in your offline compiler; it's that mixing C-style memory management with C++ code can lead to issues such as memory leaks and undefined behavior. To ensure proper memory management and compatibility with C++ features, it's recommended to use C++ memory allocation (`new` and `delete`) when working with C++ code and objects.


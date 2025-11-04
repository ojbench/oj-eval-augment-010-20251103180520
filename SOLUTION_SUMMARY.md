# Solution Summary - STLite List (Doubly-Linked List)

## Final Result
- **Score**: 100/100 ✅
- **Status**: Accepted
- **Submissions Used**: 2/6
- **Final Submission ID**: 706915

## Implementation Overview

Successfully implemented a complete doubly-linked list container similar to `std::list` with the following features:

### Core Data Structure
- **Node structure**: Contains data pointer, prev pointer, and next pointer
- **Sentinel nodes**: Used head and tail sentinel nodes (with null data) to simplify edge cases
- **Size tracking**: Maintained a count variable for O(1) size() operation

### Key Operations Implemented

1. **Constructors and Destructors**
   - Default constructor: Initializes empty list with sentinel nodes
   - Copy constructor: Deep copy of all elements
   - Assignment operator: Handles self-assignment and deep copy
   - Destructor: Properly cleans up all nodes

2. **Iterators**
   - Bidirectional iterator with proper increment/decrement
   - const_iterator support
   - **Critical fix**: Added validation to throw exceptions when:
     - Incrementing past end() (ptr->next == nullptr)
     - Decrementing before begin() (ptr->prev->data == nullptr)
     - Dereferencing invalid iterators

3. **Element Access**
   - front() and back() with empty container checks
   - Iterator-based access with proper validation

4. **Modifiers**
   - insert(): Inserts before given position
   - erase(): Removes element at position
   - push_back(), push_front(), pop_back(), pop_front()
   - clear(): Removes all elements

5. **Operations**
   - **sort()**: Uses provided sjtu::sort() with array of pointers
   - **merge()**: Merges two sorted lists by pointer manipulation (no copying)
   - **reverse()**: Reverses list by swapping prev/next pointers (no copying)
   - **unique()**: Removes consecutive duplicates

## Key Challenges and Solutions

### Challenge 1: Exception Handling in Iterators
**Problem**: Initial implementation only threw exceptions on dereferencing, but test expected exceptions on increment/decrement operations that would go out of bounds.

**Solution**: Added validation in iterator increment/decrement operators:
- Throw when incrementing past end (ptr->next == nullptr)
- Throw when decrementing before begin (ptr->prev->data == nullptr, checking for sentinel)

### Challenge 2: Sort Implementation
**Problem**: Lambda function type mismatch with sjtu::sort() template.

**Solution**: Used std::function wrapper and explicit template instantiation:
```cpp
std::function<bool(const T* const &, const T* const &)> cmp = 
    [](const T* const &a, const T* const &b) { return *a < *b; };
sjtu::sort<T*>(arr, arr + count, cmp);
```

### Challenge 3: Merge and Reverse Operations
**Problem**: Required pointer manipulation without copying/moving data.

**Solution**: 
- **merge()**: Directly manipulated node pointers to splice nodes from other list
- **reverse()**: Swapped prev/next pointers for each node, then fixed head/tail connections

## Test Results

All test groups passed:
- ✅ one: Basic operations and exception handling
- ✅ two: Dynamic type handling
- ✅ three: Advanced operations
- ✅ four: Performance tests
- ✅ five: Edge cases
- ✅ six: Complex scenarios
- ✅ All memory check tests (no memory leaks)

## Submission History

1. **Submission 706912** (Score: 83/100)
   - Failed test group "one" due to missing iterator validation
   - All other tests passed including memory checks

2. **Submission 706915** (Score: 100/100) ✅
   - Fixed iterator increment/decrement validation
   - All tests passed

## Code Quality
- Clean separation of concerns with sentinel nodes
- Proper memory management (no leaks detected)
- Efficient O(1) operations where possible
- Follows C++ best practices for container implementation


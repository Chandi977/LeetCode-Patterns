# LeetCode Patterns — Organized C++ Solutions

[![GitHub stars](https://img.shields.io/github/stars/Chandi977/LeetCode-Patterns?style=social)](https://github.com/Chandi977/LeetCode-Patterns/stargazers)
[![Language](https://img.shields.io/github/languages/top/Chandi977/LeetCode-Patterns)](https://github.com/Chandi977/LeetCode-Patterns)
[![Last Commit](https://img.shields.io/github/last-commit/Chandi977/LeetCode-Patterns)](https://github.com/Chandi977/LeetCode-Patterns/commits)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

## Overview

A curated collection of LeetCode problems systematically organized by algorithmic patterns. Each solution is implemented in **C++** with comprehensive comments, time/space complexity analysis, and executable test cases.

This repository serves as both a learning resource and quick reference guide for mastering common algorithmic patterns essential for technical interviews.

## Table of Contents

- [Features](#features)
- [Repository Structure](#repository-structure)
- [Patterns Covered](#patterns-covered)
- [Problem Index](#problem-index)
- [Getting Started](#getting-started)
- [Contributing](#contributing)
- [Resources](#resources)
- [License](#license)

## Features

- **Pattern-Based Organization**: Problems grouped by core algorithmic patterns rather than difficulty
- **Detailed Comments**: Each solution includes learning-focused inline documentation
- **Complexity Analysis**: Time and space complexity clearly stated for every solution
- **Executable Examples**: Working `main()` functions with test cases
- **Clean Code**: Following modern C++ best practices and conventions
- **Interview Ready**: Focuses on patterns frequently appearing in technical interviews

## Repository Structure

```
LeetCode-Patterns/
│
├── Two-Pointers/
│   ├── two_sum_ii.cpp
│   ├── three_sum.cpp
│   ├── four_sum.cpp
│   ├── container_with_most_water.cpp
│   ├── trapping_rain_water.cpp
│   ├── valid_palindrome.cpp
│   ├── remove_duplicates.cpp
│   ├── sort_array_by_parity.cpp
│   ├── move_zeroes.cpp
│   └── partition_list.cpp
│
├── Sliding-Window/
│   ├── longest_substring_without_repeat.cpp
│   ├── min_window_substring.cpp
│   ├── subarrays_with_k_distinct.cpp
│   └── longest_ones.cpp
│
├── Linked-List/
│   ├── has_cycle.cpp
│   ├── middle_of_linked_list.cpp
│   ├── remove_nth_from_end.cpp
│   └── partition_list.cpp
│
├── Sorting-Searching/
│   ├── quickselect_kth_largest.cpp
│   └── merge_sorted_array.cpp
│
├── Intervals/
│   ├── merge_intervals.cpp
│   └── insert_interval.cpp
│
├── Math/
│   └── happy_number.cpp
│
├── README.md
└── LICENSE
```

## Patterns Covered

### Two Pointers

Master the art of using multiple pointers to solve array and string problems efficiently.

**Key Techniques:**

- Opposite direction pointers (start/end)
- Same direction pointers (fast/slow)
- Partitioning and rearrangement
- Deduplication in sorted arrays

**Common Use Cases:** Palindrome checking, array partitioning, cycle detection, removing duplicates

### Sliding Window

Learn to efficiently process contiguous subarrays or substrings using a dynamic window.

**Key Techniques:**

- Variable-size windows
- Fixed-size windows
- "At Most K" to "Exactly K" transformation
- Frequency maps for substring problems

**Common Use Cases:** Maximum/minimum subarray problems, substring matching, optimization problems

### Linked List

Essential techniques for manipulating and traversing linked data structures.

**Key Techniques:**

- Fast and slow pointer (Floyd's algorithm)
- Dummy node patterns
- In-place reversal
- Node manipulation without extra space

**Common Use Cases:** Cycle detection, finding middle element, reversing lists, merging lists

### Sorting & Searching

Fundamental algorithms for organizing and finding data efficiently.

**Key Techniques:**

- QuickSelect for Kth element problems
- Binary search variations
- Merge operations
- Partition schemes

**Common Use Cases:** Finding Kth largest/smallest, searching in rotated arrays, merging sorted data

### Intervals

Strategies for handling range-based problems and overlapping segments.

**Key Techniques:**

- Sorting by start time
- Merge overlapping intervals
- Insert with overlap handling
- Sweep line algorithms

**Common Use Cases:** Meeting rooms, scheduling problems, range queries

### Math & Number Theory

Mathematical approaches and cycle detection in numerical sequences.

**Key Techniques:**

- Floyd's cycle detection in sequences
- Digit manipulation
- Number transformations
- Mathematical properties

**Common Use Cases:** Happy number, cycle detection in sequences, digit problems

## Problem Index

### Two Pointers

| Problem                                                                                 | Difficulty | Solution                                                                    | Key Concepts                    |
| --------------------------------------------------------------------------------------- | ---------- | --------------------------------------------------------------------------- | ------------------------------- |
| [Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)           | Easy       | [two_sum_ii.cpp](Two-Pointers/two_sum_ii.cpp)                               | Opposite pointers, sorted array |
| [Three Sum](https://leetcode.com/problems/3sum/)                                        | Medium     | [three_sum.cpp](Two-Pointers/three_sum.cpp)                                 | Deduplication, sorting          |
| [Four Sum](https://leetcode.com/problems/4sum/)                                         | Medium     | [four_sum.cpp](Two-Pointers/four_sum.cpp)                                   | Multi-pointer extension         |
| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)   | Medium     | [container_with_most_water.cpp](Two-Pointers/container_with_most_water.cpp) | Greedy, area optimization       |
| [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)               | Hard       | [trapping_rain_water.cpp](Two-Pointers/trapping_rain_water.cpp)             | Max height tracking             |
| [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)                     | Easy       | [valid_palindrome.cpp](Two-Pointers/valid_palindrome.cpp)                   | String comparison               |
| [Remove Duplicates](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | Easy       | [remove_duplicates.cpp](Two-Pointers/remove_duplicates.cpp)                 | In-place modification           |
| [Sort Array by Parity](https://leetcode.com/problems/sort-array-by-parity/)             | Easy       | [sort_array_by_parity.cpp](Two-Pointers/sort_array_by_parity.cpp)           | Partitioning                    |
| [Move Zeroes](https://leetcode.com/problems/move-zeroes/)                               | Easy       | [move_zeroes.cpp](Two-Pointers/move_zeroes.cpp)                             | In-place rearrangement          |
| [Partition List](https://leetcode.com/problems/partition-list/)                         | Medium     | [partition_list.cpp](Two-Pointers/partition_list.cpp)                       | Linked list partitioning        |

### Sliding Window

| Problem                                                                                                                         | Difficulty | Solution                                                                                    | Key Concepts             |
| ------------------------------------------------------------------------------------------------------------------------------- | ---------- | ------------------------------------------------------------------------------------------- | ------------------------ |
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Medium     | [longest_substring_without_repeat.cpp](Sliding-Window/longest_substring_without_repeat.cpp) | Variable window, hashmap |
| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)                                             | Hard       | [min_window_substring.cpp](Sliding-Window/min_window_substring.cpp)                         | Frequency matching       |
| [Subarrays With K Distinct Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)                        | Hard       | [subarrays_with_k_distinct.cpp](Sliding-Window/subarrays_with_k_distinct.cpp)               | AtMost(K) - AtMost(K-1)  |
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)                                             | Medium     | [longest_ones.cpp](Sliding-Window/longest_ones.cpp)                                         | Fixed budget window      |

### Linked List

| Problem                                                                                     | Difficulty | Solution                                                           | Key Concepts              |
| ------------------------------------------------------------------------------------------- | ---------- | ------------------------------------------------------------------ | ------------------------- |
| [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)                       | Easy       | [has_cycle.cpp](Linked-List/has_cycle.cpp)                         | Floyd's algorithm         |
| [Middle of Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)           | Easy       | [middle_of_linked_list.cpp](Linked-List/middle_of_linked_list.cpp) | Fast/slow pointers        |
| [Remove Nth Node From End](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | Medium     | [remove_nth_from_end.cpp](Linked-List/remove_nth_from_end.cpp)     | Two-pass or gap technique |
| [Partition List](https://leetcode.com/problems/partition-list/)                             | Medium     | [partition_list.cpp](Linked-List/partition_list.cpp)               | Two dummy nodes           |

### Sorting & Searching

| Problem                                                                               | Difficulty | Solution                                                                     | Key Concepts                  |
| ------------------------------------------------------------------------------------- | ---------- | ---------------------------------------------------------------------------- | ----------------------------- |
| [Kth Largest Element](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Medium     | [quickselect_kth_largest.cpp](Sorting-Searching/quickselect_kth_largest.cpp) | QuickSelect, partitioning     |
| [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)               | Easy       | [merge_sorted_array.cpp](Sorting-Searching/merge_sorted_array.cpp)           | Three pointers, backward fill |

### Intervals

| Problem                                                           | Difficulty | Solution                                             | Key Concepts               |
| ----------------------------------------------------------------- | ---------- | ---------------------------------------------------- | -------------------------- |
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | Medium     | [merge_intervals.cpp](Intervals/merge_intervals.cpp) | Sorting, overlap detection |
| [Insert Interval](https://leetcode.com/problems/insert-interval/) | Medium     | [insert_interval.cpp](Intervals/insert_interval.cpp) | Three-phase processing     |

### Math / Floyd's Cycle Detection

| Problem                                                     | Difficulty | Solution                                  | Key Concepts                |
| ----------------------------------------------------------- | ---------- | ----------------------------------------- | --------------------------- |
| [Happy Number](https://leetcode.com/problems/happy-number/) | Easy       | [happy_number.cpp](Math/happy_number.cpp) | Cycle detection, digit math |

## Getting Started

### Prerequisites

- C++ compiler supporting C++11 or later (GCC 5+, Clang 3.4+, MSVC 2015+)
- Basic understanding of data structures and algorithms

### Compilation

Each file can be compiled and run independently:

```bash
# Compile a single solution
g++ -std=c++11 -o solution Two-Pointers/two_sum_ii.cpp

# Run the executable
./solution
```

### Running Tests

Every solution file includes a `main()` function with sample test cases:

```cpp
int main() {
    // Test case 1
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);

    // Expected output: [0, 1]
    for(int idx : result) {
        cout << idx << " ";
    }
    return 0;
}
```

## Contributing

Contributions are welcome! Here's how you can help:

### Adding New Solutions

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/new-pattern-solution
   ```
3. **Follow the code structure:**

   - Place solution in the appropriate pattern folder
   - Include detailed comments explaining the approach
   - Add time and space complexity analysis
   - Provide a working `main()` with test cases
   - Use meaningful variable names
   - Follow C++ best practices

4. **Commit your changes**

   ```bash
   git commit -m "Add solution for [Problem Name]"
   ```

5. **Push to your fork and submit a Pull Request**

### Code Style Guidelines

- Use clear, descriptive variable names
- Add comments for complex logic
- Include complexity analysis at the top of each solution
- Format code consistently (consider using clang-format)
- Ensure code compiles without warnings

### Suggesting Improvements

- Open an issue to suggest new patterns or improvements
- Provide detailed descriptions of the enhancement
- Reference specific problems or patterns when applicable

## Resources

### Learning Materials

- [LeetCode](https://leetcode.com/) - Practice problems
- [NeetCode](https://neetcode.io/) - Pattern-based learning
- [AlgoMap](https://algomap.io/) - Structured learning path

### Related Repositories

- [Blind 75](https://www.teamblind.com/post/New-Year-Gift---Curated-List-of-Top-75-LeetCode-Questions-to-Save-Your-Time-OaM1orEU) - Essential problems for interviews
- [Grind 75](https://www.techinterviewhandbook.org/grind75) - Extended problem set

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- LeetCode platform for providing quality coding problems
- The competitive programming community for algorithmic insights
- Contributors who help improve and expand this repository

## Contact & Support

- **Repository**: [github.com/Chandi977/LeetCode-Patterns](https://github.com/Chandi977/LeetCode-Patterns)
- **Issues**: [Report bugs or request features](https://github.com/Chandi977/LeetCode-Patterns/issues)
- **Discussions**: [Join community discussions](https://github.com/Chandi977/LeetCode-Patterns/discussions)

---

**⭐ If this repository helps you in your interview preparation, please consider giving it a star!**

Your support motivates continued updates and improvements to the content.

---

_Last Updated: November 2025_

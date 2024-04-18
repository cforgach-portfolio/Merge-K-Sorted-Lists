#pragma once
#include <iostream>
#include <deque>
#include <omp.h>
#include <algorithm>
#include <limits>
#include "MergeKSortedLists.hpp"

using namespace std;

template <typename T>
void run(deque<deque<T>> lists) {
    for (deque<T>& list : lists) {
        sort(list.begin(), list.end());
    }

    deque<T> result = mergeKSortedLists(lists);

    for (T val : result)
        cout << val << " ";
    cout << "\n";
}


void case1() {
    deque<deque<int>> lists {
        {0, 2, 4},
        {-1, 1, 3}
    };
    run(lists);
}

void case2() {
    deque<deque<int>> lists {
        {numeric_limits<int>::min(), 2, 4},
        {-1, 1, numeric_limits<int>::max()}
    };
    run(lists);
}

void runall() {
    case1();
    case2();
}
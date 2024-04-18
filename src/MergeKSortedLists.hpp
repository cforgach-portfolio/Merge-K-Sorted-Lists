#pragma once
#include <deque>
#include <queue>
#include <functional>

using namespace std;

template <typename T>
deque<T> mergeKSortedLists(deque<deque<T>> lists) {

    function<bool(pair<int, T>, pair<int, T>)> cmp = [](pair<int, T> a, pair<int, T> b) {
        return a.second > b.second;
    };

    priority_queue<pair<int, T>, deque<pair<int, T>>, function<bool(pair<int, T>, pair<int, T>)>> Q(cmp);
    for (int i=0; i < lists.size(); i += 1) {
        if (!lists[i].empty()) {
            Q.push({i, lists[i][0]});
        }
    }

    deque<T> result;
    while (!Q.empty()) {
        auto [i, val] = Q.top(); Q.pop();
        result.push_back(val);

        lists[i].pop_front();
        if (!lists[i].empty())
            Q.push({i, lists[i][0]});
    }
    return result;
}
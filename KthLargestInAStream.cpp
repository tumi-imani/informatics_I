// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int count_k;
priority_queue<int, vector<int>, greater<int>> pq;

void KthLargest(int k, vector<int> &nums){
    count_k = k;
    for (int x : nums) {
        pq.push(x);
        if (pq.size() > count_k) {
            pq.pop();
        }
    }
}

int add(int val){
    pq.push(val);
    if (pq.size() > count_k) {
        pq.pop();
    }
    return pq.top();
}

// int main(){

//     return 0;
// }

// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n,k;

long long maxMedian(vector<long long> &v){
    sort(v.begin(),v.end());
    long long mid = n/2, operations, median = v[mid];

    for (long long i = mid + 1; i < n; i++) {
        operations = (v[i]-median) * (i-mid);
        if (operations <= k) {
            k -= operations;
            median = v[i];
        }
        else {
            median += k / (i-mid);
            k = 0;
            break;
        }
    }
    median += k / (n-mid);

    return median;
}

int main(){
    cin >> n >> k;
    vector <long long> v(n);
    for (long long i=0;i<n;i++){
        cin >> v[i];
    }
    cout << maxMedian(v) << "\n";

    return 0;
}

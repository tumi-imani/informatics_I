#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
 
using namespace std;
 
long long n, a, b;
 
long long max_sum(vector<long long> &v){
    vector<long long> pref_sum(n+1, 0);
    for(int p=1;p<=n;p++){
        pref_sum[p] = pref_sum[p-1] + v[p-1];
    }
    long long maxSum = pref_sum[a];

    set<pair<long long, long long>> s;

    for(int r=a;r<=n;r++){
        long long l = r-a;
        s.insert({pref_sum[l], l});

        long long invalid = r-b-1;
        if(invalid >= 0){
            s.erase({pref_sum[invalid], invalid});
        }

        long long currentSum = pref_sum[r] - s.begin()->first;

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
 
int main(){
    cin >> n >> a >> b;
    vector<long long> v(n);
    for(long long x=0;x<n;x++){
        cin >> v[x];
    }
 
    cout << max_sum(v) << "\n";
 
    return 0;
}


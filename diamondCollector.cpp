// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;

int max_diamonds(vector<int> &d) {
    sort(d.begin(), d.end());
    vector<int> left(n), right(n);

    int l = 0;
    for (int r=0; r<n; r++) {
        while (d[r] - d[l] > k) {
            l++;
        }
        int current = r - l + 1;
        if (r == 0)
            left[r] = current;
        else
            left[r] = max(left[r-1], current);
    }

    int r = n - 1;
    for (int i=n-1; i>=0; i--) {
        while (d[r] - d[i] > k) {
            r--;
        }
        int current = r - i + 1;
        if (i == n - 1)
            right[i] = current;
        else
            right[i] = max(right[i+1], current);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, left[i] + right[i+1]);
    }

    return ans;
}


int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    cin >> n >> k;
    vector <int> diamond_sizes(n);
    for(int i=0;i<n;i++){
        cin >> diamond_sizes[i];
    }

    cout << max_diamonds(diamond_sizes) << "\n";

    return 0;
}

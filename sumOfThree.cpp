#include <bits/stdc++.h>

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>

using namespace std;

int n,x;
vector <int> v;
vector<pair<int, int>> arranged;

void segment(vector<int> &v){
    bool found = false;

    arranged.resize(n);
    for(int i = 0;i < n;i++){
        arranged[i].first = v[i];
        arranged[i].second = i;
    }
    sort(arranged.begin(), arranged.end());

    for(int j=0;j<(n-2);j++){
        int l = j+1, r = n-1;
        
        while(l < r){
            int sum = arranged[j].first + arranged[l].first + arranged[r].first;
            if(sum == x){
                cout << arranged[j].second + 1 << " " 
                    << arranged[l].second + 1 << " " 
                    << arranged[r].second + 1 << "\n";
                found = true;
                break;
            }else if (sum < x){
                l++;
            }else r--;
        }
        if(found == true) break;
    }

    if(found == false){
        cout << "IMPOSSIBLE\n";
    }

    return; 
}

int main(){
    cin >> n >> x;
    v.resize(n);
    for(int k=0;k<n;k++){
        cin >> v[k];
    }
    segment(v);
    return 0;
}
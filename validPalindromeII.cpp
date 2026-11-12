// #include <bits/stdc++.h>

#include <iostream>

using namespace std;

bool isPalindrome(string &s, int l, int r, int removed) {
    if (l >= r) return true;
    if (s[l] == s[r]) {
        return isPalindrome(s, l + 1, r - 1, removed);
    }
    if (removed == 1) return false;

    bool isPal = isPalindrome(s, l+1, r, removed+1) || isPalindrome(s, l, r-1, removed+1);

    return isPal;
}

bool validPalindrome(string s) {
    return isPalindrome(s, 0, s.size()-1, 0);
}

int main(){
    string s;
    cin >> s;
    cout << validPalindrome(s);

    return 0;
}


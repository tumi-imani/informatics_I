// #include <bits/stdc++.h>

#include <iostream> 
#include <stack>
#include <string>
using namespace std;

string s;
stack <char> brackets;

bool isValid(string s){
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            brackets.push(s[i]);
        }else {
            if (brackets.empty()) return false;
            if ((brackets.top() == '{' && s[i] == '}') ||
                (brackets.top() == '[' && s[i] == ']') ||
                (brackets.top() == '(' && s[i] == ')')){
                brackets.pop();
            }else return false;
        }
    }
    return brackets.empty();
}

int main(){
    cin >> s;
    cout << isValid(s) << "\n";
    return 0;
}
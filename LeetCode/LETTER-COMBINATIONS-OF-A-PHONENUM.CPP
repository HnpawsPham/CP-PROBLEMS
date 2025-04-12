#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
string digits;
vector<string> res;
unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

void sol(int i, string s){
    if(i == n){
        if(!s.empty()) res.push_back(s);
        return;
    }

    for(char x : mp[digits[i]])
        sol(i + 1, s + x);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>digits;
    n = digits.length();

    sol(0, "");
    for(string x : res) cout<<x<<el;

    return 0;
}
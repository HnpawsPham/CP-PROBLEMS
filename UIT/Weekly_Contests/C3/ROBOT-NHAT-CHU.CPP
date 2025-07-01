#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, s);
    int n = s.length();
    unordered_map<char, int> mp;

    for(const char& x : s)
        if(!mp[x] || x == ' ') {
            cout<<x;
            mp[x]++;
        }

    return 0;
}
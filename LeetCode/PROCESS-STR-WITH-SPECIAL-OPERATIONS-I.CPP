#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<char> res;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if ('a' <= s[i] && s[i] <= 'z')
            res.push_back(s[i]);
        else if (s[i] == '*' && !res.empty())
            res.pop_back();
        else if (s[i] == '#' && !res.empty()) {
            vector<char> tmp(res.begin(), res.end());
            for (char ch : tmp)
                res.push_back(ch);
        } else if (s[i] == '%')
            reverse(res.begin(), res.end());
    }
    
    string ss = "";
    for (const char& x : res)
        ss += x;
    cout<<ss;
    return 0;
}
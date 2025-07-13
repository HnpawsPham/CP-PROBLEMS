#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    deque<char> res;
    int n = s.length();

    for(int i = 0; i < n; i++){
        if('a' <= s[i] && s[i] <= 'z') 
            res.push_back(s[i]);
        else if(s[i] == '*' && !res.empty()) 
            res.pop_back();
        else if(s[i] == '#' && !res.empty()) {
            vector<char> tmp(res.begin(), res.end());
                for(char ch: tmp)
                    res.push_back(ch);
        }
        else if(s[i] == '%') 
            reverse(res.begin(), res.end());
    }
    string ss = "";
    for(const char& x : res) ss += x;
    cout<<ss;
    return 0;
}
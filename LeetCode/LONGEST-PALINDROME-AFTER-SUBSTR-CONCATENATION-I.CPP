#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, m, maxlen = 0;

bool check(string s, int n) {
    for (int i = 0; i < n / 2; ++i) 
        if (s[i] != s[n - i - 1]) return false;
    return true;
}

vector<string> makeSubs(string s, int n) {
    vector<string> v;
    v.push_back("");

    for (int i = 0; i < n; i++) 
        for (int j = 1; j <= n - i; j++)
            v.push_back(s.substr(i, j));
    return v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>t;
    n = s.length(), m = t.length();

    vector<string> ss = makeSubs(s, n);
    vector<string> tt = makeSubs(t, m);
    
    for (string s1 : ss) 
        for (string s2 : tt) {
            int len = s1.size() + s2.size();

            if (len <= maxlen) continue;
            if (check(s1 + s2, len)) maxlen = len;
        }
    cout<<maxlen;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    string s = "|";
    for(char x : str) s = s + x + '|';

    int n = s.length(), r = 0, c = 0, len = 0, final_c = 0;
    int p[n] = {};

    for(int i = 1; i < n; i++){
        if(i < r)
            p[i] = min(p[2 * c - i], r - i);
        
        while(i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
            p[i]++;
        
        if(i + p[i] > r){
            r = i + p[i];
            c = i;
        }

        if(p[i] > len){
            len = p[i];
            final_c = i;
        }
    }

    int st = (final_c - len) / 2;
    int en = st + len - 1;

    string sub = str.substr(st, en - st);
    for(int i = n - 1; i >= en - st; i--) cout<<str[i];
    for(int i = st; i < n; i++) cout<<str[i];
    // cout<<sub;
    return 0;
}
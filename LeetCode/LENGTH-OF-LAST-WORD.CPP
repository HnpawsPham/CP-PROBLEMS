#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    getline(cin, s);
    int st = 0, last_st = 0, en = 0, n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] == ' ') st = n;
        else{
            st = min(st, i);
            last_st = st;
            en = i;
        } 
    }
    
    cout<<en - last_st + 1;
    return 0;
}
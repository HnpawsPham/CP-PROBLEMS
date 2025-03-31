#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
vector<string> res;

void sol(int open, int close, string s){
    if(open == 0 && close == 0) {
        res.push_back(s);
        return;
    }

    if(open > 0) sol(open - 1, close, s + '(');
    if(close > open) sol(open, close - 1, s + ')');
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    sol(n, n, "");
    for(string s : res) cout<<s<<el;

    return 0;
}
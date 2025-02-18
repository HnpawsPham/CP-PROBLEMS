#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;
string str;

void solve(ll x){
    string ss = "";
    
    while(x > 0){
        if(x & 1) ss += '1';
        else ss += '0';
        x >>= 1;
    }
    for(int i = ss.length() - 1; i>=0 ;i--) cout<<ss[i];
    return;
}

int main(){
    freopen(".\\txt\\NHI-PHAN.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>str;
    ll num = bitset<32>(str).to_ullong() * k;
    solve(num);
    return 0;
}
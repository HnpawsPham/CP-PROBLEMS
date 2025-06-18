#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int MOD = 1e9 + 7;

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<ppow(2, n);

    return 0;
}
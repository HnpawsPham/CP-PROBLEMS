#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;
const ll MOD = 1e9 + 7;
const int maxn = 1e5 + 2;
ll ppow[maxn];

// ll ppow(ll a, int b){
//     if(b == 0) return 1LL;
//     ll half = ppow(a, b / 2);

//     if(b & 1) return half * half % MOD * a % MOD;
//     return half * half % MOD;
// }

void calc(){
    ppow[0] = 1;
    for(int i = 1; i < maxn; i++)
        ppow[i] = ppow[i - 1] * 2 % MOD;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    ll cnt = 0;
    int l = 0, r = n - 1;

    calc();
    
    while(l <= r){
        if(a[l] + a[r] <= k){
            cnt = (cnt + ppow[r - l]) % MOD;
            l++;
        }
        else r--;
    }
    cout<<cnt;
    return 0;
}
// 4 9
// 3 5 6 7
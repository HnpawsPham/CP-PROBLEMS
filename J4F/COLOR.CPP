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

int n, k;
const int MOD = 1e9 + 7;

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return 1LL * half * half % MOD * 1LL * a % MOD;
    return 1LL * half * half % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;

    n = n - k + 1;
    if(k > n) return cout<<0, 0;

    int top = 1, bot = 1;
    for(int i = 1; i <= k; i++){
        top = 1LL * top * (((n - i + MOD) % MOD + 1) % MOD) % MOD;
        bot = 1LL * bot * i % MOD;
    }
    cout<<1LL * top * ppow(bot, MOD - 2) % MOD;
    return 0;
}
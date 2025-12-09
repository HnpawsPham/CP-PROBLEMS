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

const int MOD = 1e9 + 7;
const int maxn = 2e5 + 3;
int l[maxn], r[maxn];

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return 1LL * half * half % MOD * a % MOD;
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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    for(const int& x : a) r[x]++;

    int res = 0;
    for(int x : a){
        if(r[x] > 0) r[x]--;
        res = (res + 1LL * l[x * 2] * r[x * 2] % MOD) % MOD;
        l[x]++;    
    }
    cout<<res;
    return 0;
}

// 3
// 6 3 6

// 4
// 0 1 0 0

// 5
// 8 4 2 8 4



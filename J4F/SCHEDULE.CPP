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

int n, m;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;
int a[maxn];

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return 1LL * half * 1LL * half % MOD * 1LL * a % MOD;
    return 1LL * half * 1LL * half % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];

    if(m == 1){
        int res = 0;
        for(int i = 0; i < n; i++)
            res = (res + ppow(2, a[i])) % MOD;
        cout<<res;
    }
    else cout<<ppow(2, *max_element(a, a + n));
    return 0;
}
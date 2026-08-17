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
#define taskname "PASSWORD"

int n;
const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll MODEXP = 2 * (MOD - 1);
int a[maxn], cnt[maxn];

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll pass = 1;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        pass = pass * a[i] % MOD;
        cnt[a[i]]++;
    }

    ll cntdiv = 1;
    for(int i = 0; i < maxn; i++)
        cntdiv = cntdiv * (cnt[i] + 1) % MODEXP; 

    cntdiv /= 2;
    cout<<ppow(pass, cntdiv);
    return 0;
}
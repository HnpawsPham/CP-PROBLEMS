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

const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
int spf[maxn] = {0}, p[maxn] = {0};

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

void sieve(){
    for(int i = 2; i * i <= maxn; i++)
        if(!spf[i])
            for(int j = i; j < maxn; j+=i)
                spf[j] = i;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
 
    sieve();
    for(int x : a){
        int tmp = x;
        while(tmp > 1){
            int cnt = 0, k = spf[tmp];
            while(tmp % k == 0){
                tmp /= k;
                cnt++;
            }
            p[k] = max(p[k], cnt);
        }
    }

    ll res = 1;
    for(int i = 2; i < maxn; i++)
        if(p[i]) res = res * ppow(i, p[i] + (p[i] % 2)) % MOD;
    cout<<res;
    return 0;
}

// 5
// 3 2 4 3 1
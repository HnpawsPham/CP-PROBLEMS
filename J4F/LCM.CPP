#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, a, b;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
int spf[maxn], cntp[maxn] = {0};

void sieve(){
    for(int i = 2; i < maxn; i++)
        spf[i] = i;
        
    for(int i = 2; i <= sqrt(maxn); i++)
        if(spf[i] == i)
            for(int j = i * i; j < maxn; j+=i)
                spf[j] = i;
    return;
}

void calc_p(int x){
    while(x > 1){
        cntp[spf[x]]++;
        x /= spf[x];
    }
    return;
}

ll sol(){
    cin>>a>>b;

    ll x = 1;
    for(int i = a; i <= b; i++)
        calc_p(i);
    
    ll res = 1;
    for(int i = 2; i < maxn; i++)
        if(cntp[i])
            res = res * (2 * cntp[i] % MOD + 1 % MOD) % MOD;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    sieve();

    while(tc--){
        memset(cntp, 0, sizeof cntp);
        cout<<sol()<<el;
    }

    return 0;
}

// 2
// 2 3
// 5 5
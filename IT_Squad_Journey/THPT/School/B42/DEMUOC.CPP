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

ll n;
int l, r;
const int maxn = 2e6 + 5;
int spf[maxn], cntp[maxn] = {0};
ll mulp[maxn];

void sieve(){
    for(int i = 0; i < maxn; i++) {
        mulp[i] = 1;
        spf[i] = -1;
    }
    cntp[1] = 1;
    
    for(int i = 2; i * i < maxn; i++)
        if(spf[i] == -1){
            spf[i] = i;
            for(int j = i * i; j < maxn; j+=i)
                if(spf[j] == -1) spf[j] = i;
        }

    for(int i = 2; i < maxn; i++){
        if(spf[i] == -1) spf[i] = i;
        if(spf[i] == i){
            cntp[i] = 2;
            mulp[i] = i;
        }
        else{
            int x = i, cnt = 0;
            while(x % spf[i] == 0){
                x /= spf[i];
                cnt++;
            }
            cntp[i] = cntp[x] * (cnt + 1);
            mulp[i] = mulp[x] * spf[i];
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r;
    sieve();

    ll res = 0;
    ll m = min(1LL * maxn - 1, n);
    for(ll i = 1; i <= m; i++)
        if(i * mulp[i] <= n && l <= cntp[i] && cntp[i] <= r) res++;

    cout<<res;
    return 0;
}

// 400 2 2

// 400 2 3
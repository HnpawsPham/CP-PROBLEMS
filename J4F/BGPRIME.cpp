#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int l, r;
const int maxn = 2 * (int)1e6 + 5;
vector<ll> nprime(maxn, 1), f(maxn, 0);

void sieve(){
    for(int i = 2; i <= sqrt(maxn); i++){
        if(nprime[i] == 1)
            for(int j = i; j <= maxn; j+=i) 
                nprime[j] *= i;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>l>>r;
    sieve();

    ll res = 0;

    for(int i = l; i <= r; i++) f[nprime[i]]++;

    for(int i = 2; i <= r; i++){
        res += f[i]*(f[i] - 1)/2;
    }
    cout<<res;

    return 0;
}
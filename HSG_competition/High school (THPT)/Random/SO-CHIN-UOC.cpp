#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
#define el "\n"

int t;
ll n;
const int maxn = (int)1e5 + 2;
bool nprime[maxn];

void sieve(){
    for(int i = 2; i < maxn; ++i){
        if(!nprime[i])
            for(int j = i + i; j < maxn; j += i) nprime[j] = 1;
    }
    return;
}

bool check_prime(ll x){
    if(x < 2) return 0;
    if(x < maxn) return !nprime[x];
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0) return 0;
    return 1;
}

bool sol(ll a){
    for(int i = 2; i < maxn; ++i){
        if(!check_prime(i)) continue;
        ll p = 1LL * i * i;
        if(a % p == 0){
            ll q = a / p;
            ll sqrt_q = (ll)sqrt(q);
            if(1LL * sqrt_q * sqrt_q == q && check_prime(sqrt_q) && q != p)
                return 1;           
        }
    }

    for(int i = 2; i <= 177; ++i){
        if(nprime[i]) continue;
        ll p = 1;
        for(int j = 0; j < 8 && p <= a; ++j){
            p *= 1LL * i;
        }

        if(p == a) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    sieve();
    while(t--){
        cin>>n;
        cout<<(sol(n) ? "YES" : "NO")<<el;
    }
    return 0;
}
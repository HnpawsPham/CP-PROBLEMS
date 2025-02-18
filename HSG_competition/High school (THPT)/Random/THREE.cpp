#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int m;
ll n;
const int maxn = (int)1e6 + 5;
bool nprime[maxn];

void sieve(){
    for(int i = 2; i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i + i; j < maxn; j+=i) nprime[j] = 1;
    return;
}

bool check(ll x){
    if(x < 3) return 0;
    ll sq = sqrt(x);
    if(sq * sq != x) return 0; 
    if(sq < maxn) return !nprime[sq];

    for(ll i = 2; i * i <= sq; i++)
        if(sq % i == 0) return 0;

    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m;
    sieve();

    while(m--){
        cin>>n;
        cout<<check(n)<<el;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

const int maxn = 1e6 + 5;
bitset<maxn> nprime;

void sieve(){
    nprime[0] = nprime[1] = 1;

    for(int i = 2; i < sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    if(n == 2) return cout<<a[n], 0;

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    sieve();

    ll pl = p[1], res = LLONG_MIN;
    for(int r = 3; r <= n; r++){
        if(!nprime[r]){
            res = max(res, p[r] - pl);
            pl = min(pl, p[r - 1]);
        }
    }
    cout<<res;
    return 0;
}
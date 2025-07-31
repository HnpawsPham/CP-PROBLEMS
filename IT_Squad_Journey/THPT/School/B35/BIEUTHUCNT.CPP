#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

const int maxn = 3e6 + 5;
bitset<maxn> nprime;

void sieve(){
    nprime[0] = nprime[1] = 1;

    for(int i = 2; i < sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j += i)
                nprime[j] = 1;
    return;
}

int main(){
    freopen("BIEUTHUCNT.INP", "r", stdin);
    freopen("BIEUTHUCNT.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    sieve();

    ll cnt = 0;
    for(int p = 2; p < 3 * n; p++){
        if(nprime[p]) continue;

        int l = max(1, (p - n + 1) / 2);
        int r = min(n, (p - 1) / 2);

        if(l <= r)
            cnt += (r - l + 1);
    }
    cout<<cnt;
    return 0;
}
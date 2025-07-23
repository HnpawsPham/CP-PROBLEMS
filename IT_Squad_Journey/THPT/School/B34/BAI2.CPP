#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el '\n'

int t, x;
const int maxn = 3e6 + 5;
bitset<maxn> nprime;
vector<ll> p;

void sieve(){
    nprime[0] = nprime[1] = 1;

    for(int i = 2; i < sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i + i; j < maxn; j+= i)
                nprime[j] = 1;

    for(int i = 2; i < maxn; i++)
        if(!nprime[i]) p.push_back(1LL * i * i);
    return;
}

int main(){
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    sieve();

    while(t--){
        cin>>x;
        int pos = lower_bound(p.begin(), p.end(), x) - p.begin();
        if(p[pos] > x) pos--;

        cout<<pos + 1<<el;
    }
    return 0;
}
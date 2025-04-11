#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t;
ll x;
const int maxn = 3e6;
bool nprime[maxn];
vector<ll> beautiful;

void sieve(){
    nprime[0] = nprime[1] = 1;

    for(int i = 2;  i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i + i; j < maxn; j+=i)
                nprime[j] = 1;

    for(int i = 2; i < maxn; i++)
        if(!nprime[i]) beautiful.push_back(1LL * i * i);

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

    for(int i = 1; i < t; i++){
        cin>>x;
        int pos = lower_bound(beautiful.begin(), beautiful.end(), x) - beautiful.begin();
        if(beautiful[pos] > x) pos--;

        cout<<pos + 1<<el;
    }
    cin>>x;
    int pos = lower_bound(beautiful.begin(), beautiful.end(), x) - beautiful.begin();
    if(beautiful[pos] > x) pos--;

    cout<<pos + 1;
    return 0;
}

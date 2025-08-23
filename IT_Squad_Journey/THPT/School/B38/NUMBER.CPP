#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e7 + 5;
bitset<maxn> nprime;
vector<ll> num;

void sieve(){
    for(int i = 2; i * i <= maxn; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;

    for(int i = 2; i < maxn; i++)
        if(!nprime[i]) num.push_back(1LL * i * i);
    return;
}

int main(){
    freopen("NUMBER.INP", "r", stdin);
    freopen("NUMBER.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    ll l, r;
    cin>>l>>r;
    // for(int i = 0; i < 31; i++) cout<<num[i]<<" ";
    // cout<<el;
 
    ll st = lower_bound(num.begin(), num.end(), l) - num.begin();
    ll en = upper_bound(num.begin(), num.end(), r) - num.begin();
    cout<<en - st;
    return 0;
}
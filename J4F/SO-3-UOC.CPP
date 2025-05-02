#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int maxn = 2e5 + 5;
bool nprime[maxn];
vector<ll> num;

void sieve(){
    for(int i = 2; i * i < maxn; i++){
        if(!nprime[i])
            for(int j = i + i; j < maxn; j += i)
                nprime[j] = 1;
    }
    for(int i = 2; i < maxn; i++)
        if(!nprime[i])
            num.push_back(1LL * i * i);
    return;
}

int main(){
    // freopen("SDB.INP", "r", stdin);
    // freopen("SDB.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sieve();

    for(ll x : a){
        int pos = lower_bound(num.begin(), num.end(), x) - num.begin();
        cout<<num[pos]<<" ";
    }

    return 0;
}
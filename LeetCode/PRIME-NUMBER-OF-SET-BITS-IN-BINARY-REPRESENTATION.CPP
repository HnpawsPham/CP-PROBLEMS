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
//#define taskname ""

const int maxn = 33;
bitset<maxn> nprime;

void sieve(){
    nprime[1] = nprime[0] = 1;
    for(int i = 2; i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    cin>>l>>r;

    sieve();
    int cnt = 0;
    for(int i = l; i <= r; i++)
        if(!nprime[__builtin_popcount(i)]) cnt++;
    cout<<cnt;
    return 0;
}
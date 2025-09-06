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

void sieve(){
    nprime[0] = nprime[1] = 1;

    for(int i = 2; i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q, n;
    cin>>q;
    sieve();
    while(q--){
        cin>>n;
        if(!nprime[n]) cout<<"YES"<<el;
        else cout<<"NO"<<el;
    }

    return 0;
}
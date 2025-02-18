#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m, node;
const int maxn = 2 * (int)1e5 + 5;
ll a[maxn * 4], b[maxn];

void build(){
    for(int i = node; i > 1; i--) a[i] = max(a[i * 2], a[i * 2 + 1]);
    return;
}

void update(int pos, ll val){
    pos += node;
    a[pos] = val;

    for(pos /= 2; pos > 0; pos /= 2)
        a[pos] = max(a[pos * 2], a[pos * 2 + 1]);
    return;
}

ll get(ll x){
    int l = 1, r = node;
    ll res = 0;

    while(l <= r){
        int mid = (l + r)/2;

        
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    node = n + (n % 2);
    for(int i = 1; i<=n;i++) cin>>a[i + node];
    for(int i = 1; i<=m;i++) cin>>b[i];

    build();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m;
const int maxn = 1e5 + 5;
ll t[maxn] = {}, a[maxn];

void init(int i, ll val){
    while(i <= n){
        t[i] += val;
        i += (i & -i);
    }
    return;
}

void update(int i, ll val){
    ll x = val - a[i];
    a[i] = val;

    while(i <= n){
        t[i] += x;
        i += (i & -i);
    }
    return;
}

ll sum(int i){
    ll res = 0;

    while(i > 0){
        res += t[i];
        i -= (i & -i);
    }
    return res;
}

int main(){
    freopen("MATTHU.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        init(i, a[i]);
    }

    int opt, x, y;
    ll w, k;
    while(m--){
        cin>>opt>>x;
        if(opt == 1){
            cin>>y;
            cout<<sum(y) - sum(x - 1)<<el;
        }
        else if(opt == 2){
            cin>>y>>w;
            for(int i = x; i <= y; i++)
                update(i, a[i] % w);
        }
        else{
            cin>>k;
            update(x, k);
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, node = 1;
const int maxn = 2e5 + 5;
const ll oo = LLONG_MAX;
ll a[4 * maxn];

void build(){
    for(int i = node - 1; i >= 0; i--)
        a[i] = min(a[2 * i], a[2 * i + 1]);
    return;
}

ll query_min(int l, int r){
    ll res = oo;

    l += node;
    r += node;

    while(l <= r){
        if(l % 2 == 1){
            res = min(res, a[l]);
            l++;
        }
        if(r % 2 == 0){
            res = min(res, a[r]);
            r--;
        }
        r /= 2;
        l /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(node < n) node *= 2;

    ll maxx = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i + node];
        maxx = max(maxx, a[i + node]);
    }
    
    build();
    
    cout<<maxx<<" ";
    
    for(int len = 2; len <= n; len++){
        maxx = 0;
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            maxx = max(maxx, query_min(i, j));
        }
        cout<<maxx<<" ";
    }
    return 0;
}
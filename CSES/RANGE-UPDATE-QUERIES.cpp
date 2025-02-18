#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, q, node;
const int maxn = 2 * (int)1e5 + 5;
ll a[maxn * 4];

void build_tree(){
    for(int i = node; i > 1; i--) a[i] = a[i * 2] + a[i * 2 + 1];
    return;
}

void update(int pos, ll val){
    pos += node;
    a[pos] += val;
    
    for(pos /= 2; pos; pos /= 2) a[pos] = a[2 * pos + 1] + a[2 * pos];
    return;
}

ll get(int l, int r){
    ll res = 0;
    
    for(l += node, r += node + 1; l < r; l /= 2, r /= 2){
        if(l & 1) res += a[l++];
        if(r & 1) res += a[--r];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    node = n + (n % 2);
    ll prev = 0;
    
    for(int i = 1; i <= n; i++) {
        ll x;
        cin>>x;
        a[i + node] = x - prev;
        prev = x;
    }

    build_tree();

    while(q--){
        int c;
        cin>>c;

        if(c == 1){
            int l, r; ll val;
            cin>>l>>r>>val;
            update(l, val);
            update(r + 1, -val);
        }
        else{
            int k;
            cin>>k;
            cout<<get(1, k)<<el;
        }
    }

    return 0;
}
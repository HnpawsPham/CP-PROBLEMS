#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, q, node;
const int maxn = 2 * (int)1e5 + 5;
ll a[maxn * 4];

void build(){
    for(int i = node; i > 1; i--) a[i] = a[i * 2] + a[i * 2 + 1];
    return;
}

ll get(int pos){
    return a[pos + node];
}

void update(int l , int r, ll u){
    l += node;
    r += node;

    a[l] += u;
    a[r + 1] -= u;

    do{
        l /= 2;
        r /= 2;

        if(l % 2 == 1){
            a[l] = a[2 * l] + a[2 * l + 1];
            l++;
        }
        if(r % 2 == 0){
            a[r] = a[2 * r] + a[2 * r + 1];
            r--;
        }
    }
    while(l <= r);

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    a[0] = 0;
    cin>>n>>q;
    node = n + (n % 2);
    for(int i = 1; i <= n; i++) {
        int pos = i + node;
        cin>>a[pos];
        a[pos] = a[pos] - a[pos - 1];
    }

    build();

    while(q--){
        int c;
        cin>>c;

        if(c == 1){
            int l, r; ll val;
            cin>>l>>r>>val;
            update(l, r, val);
        }
        else{
            int k;
            cin>>k;
            cout<<get(k)<<el;
        }
    }

    return 0;
}
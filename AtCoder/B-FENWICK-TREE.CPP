#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, q;
const int maxn = 5e5 + 5;
ll bit[maxn] = {0};

void update(int i, int val){
    for(; i <= n; i += (i & -i))
        bit[i] += val;
    return;
}

ll query(int i){
    ll sum = 0;
    for(; i > 0; i -= (i & -i))
        sum += bit[i];
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        update(i + 1, x);
    }

    int opt, x, y;
    while(q--){
        cin>>opt>>x>>y;
        if(opt == 0) update(x + 1, y);
        else cout<<query(y) - query(x)<<el;
    }
    return 0;
}
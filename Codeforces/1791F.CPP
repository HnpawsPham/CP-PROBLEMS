#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, n, q;
const int maxn = 2e5 + 5;
ll t[maxn * 4] = {0};
int a[maxn];

int calc(int x){
    int sum = 0;
    while(x > 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void build(int i, int l, int r){
    if(l == r) {
        t[i] = (a[l] < 10);
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i] = t[2 * i] & t[2 * i + 1];
    return;
}

void update(int i, int st, int en, int l, int r){
    if(t[i] || st > r || en < l) return;
    if(st == en){
        a[st] = calc(a[st]);
        t[i] = (a[st] < 10);
        return;
    }

    int mid = (st + en ) / 2;
    update(2 * i, st, mid, l, r);
    update(2 * i + 1, mid + 1, en, l, r);
    t[i] = t[2 * i] & t[2 * i + 1];
    return;
}

int query(int i, int l, int r, int pos){
    if(l == r) return a[l];

    int mid = (l + r) / 2;
    if(pos <= mid) return query(2 * i, l, mid, pos);
    return query(2 * i + 1, mid + 1, r, pos);
}

void sol(){
    for(int i = 1; i <= n; i++) cin>>a[i];
    build(1, 1, n);

    int opt, x, y;
    while(q--){
        cin>>opt>>x;
        if(opt == 1){
            cin>>y;
            update(1, 1, n, x, y);
        }
        else cout<<query(1, 1, n, x)<<el;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin>>n>>q;
        sol();
    }

    return 0;
}
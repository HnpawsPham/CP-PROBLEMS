#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 3e5 + 5;
int t[maxn * 4] = {0};

void update(int i, int st, int en, int l, int r, int val){
    if(st > r || en < l || t[i]) return;
    if(st >= l && en <= r){
        t[i] = val;
        return;
    }

    int mid = (st + en) / 2;
    update(2 * i, st, mid, l, r, val);
    update(2 * i + 1, mid + 1, en, l, r, val);
    return;
}

int query(int i, int l, int r, int pos){
    if(l == r) return t[i];

    int mid = (l + r) / 2;
    int res = t[i], tmp;

    if(pos <= mid) 
        tmp = query(2 * i, l, mid, pos);
    else tmp = query(2 * i + 1, mid + 1, r, pos);

    if(tmp) return tmp;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int l, r, x;
        cin>>l>>r>>x;
        update(1, 1, n, l, x - 1, x);
        update(1, 1, n, x + 1, r, x);
    }
    for(int i = 1; i <= n; i++)
        cout<<query(1, 1, n, i)<<" ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 2e5 + 5;
int a[maxn], w[maxn];
ll t[maxn * 4] = {0};

void update(int i, int l, int r, int pos, ll val){
    if(l == r){
        t[i] = max(val, t[i]);
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) update(2 * i, l, mid, pos, val);
    else update(2 * i + 1, mid + 1, r, pos, val);
    
    t[i] = max(t[2 * i], t[2 * i + 1]);
    return; 
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    return max(query(2 * i, st, mid, l, r), query(2 * i + 1, mid + 1, en, l , r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i= 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>w[i];

    for(int i = 1; i <= n; i++)
        update(1, 1, n, a[i], query(1, 1, n, 1, a[i] - 1) + w[i]);
    cout<<query(1, 1, n, 1, n);
    return 0;
}
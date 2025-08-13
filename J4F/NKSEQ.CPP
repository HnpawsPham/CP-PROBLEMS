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
const int maxn = 1e5 * 2 + 5;
const int oo = 1e9 + 5;
int a[maxn], p[maxn];
int t[maxn * 4] = {0};

void build(int i, int l, int r){
    if(l == r){
        t[i] = p[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);

    t[i] = min(t[2 * i], t[2 * i + 1]);
    return;
}

int query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return oo;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    return min(query(2 * i, st, mid, l, r), query(2 * i + 1, mid + 1, en, l, r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        a[n + i] = a[i];
    }

    for(int i = 1; i <= n * 2; i++)
        p[i] = p[i - 1] + a[i];

    build(1, 1, n * 2);
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        int pr = query(1, 1, n * 2, i, i + n - 1);
        if(pr - p[i - 1] > 0) cnt++;
    }
    cout<<cnt;
    return 0;
}
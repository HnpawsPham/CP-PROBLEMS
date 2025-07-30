#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n, m;
const int maxn = 2e5;
int t[maxn * 4] = {0};

void update(int i, int st, int en, int l, int r, int val, int lvl){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        t[i] = val;
        return;
    }

    int mid = (st + en) / 2;
    update(2 * i, st, mid, l, r, val, lvl - 1);
    update(2 * i + 1, mid + 1, en, l, r, val, lvl - 1);

    if(lvl % 2) t[i] = t[2 * i] | t[2 * i + 1];
    else t[i] = t[2 * i] ^ t[2 * i + 1];
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    n = 1 << n;

    int lvl = __lg(n);
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        update(1, 1, n, i, i, x, lvl);
    }
    while(m--){
        int x, y;
        cin>>x>>y;
        update(1, 1, n, x, x, y, lvl);
        cout<<t[1]<<el;
    }
    return 0;
}
#include <iostream>
using namespace std;
using ll = long long;
#define el '\n'

int n, k;
const int maxn = 1e5 + 5;
const ll oo = 1e9 + 5;
ll t[maxn * 4], dp[maxn] = {0};

void update(int i, int l, int r, int pos){
    if(l == r){
        t[i] = dp[pos];
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) update(2 * i, l, mid, pos);
    else update(2 * i + 1, mid + 1, r, pos);

    t[i] = max(t[i * 2], t[2 * i + 1]);
    return;
}

ll getmax(int i, int st, int en, int l, int r){
    if(l > r) return 0LL;

    if(st > r || en < l) return -oo;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    return max(getmax(2 * i, st, mid, l, r), getmax(2 * i + 1, mid + 1, en, l, r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    for(int i = 0; i < maxn * 4; i++) t[i] = -oo;

    for(int i = 1; i <= n; i++){
        int l = max(1, i - k), r = max(1, i - 1);

        dp[i] = max(getmax(1, 1, n, l, r), 0LL) + a[i];
        update(1, 1, n, i);
    }
    cout<<max(0LL, getmax(1, 1, n, 1, n));
    return 0;
}
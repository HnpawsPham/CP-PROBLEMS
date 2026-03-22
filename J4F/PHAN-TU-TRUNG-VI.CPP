#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

const int MOD = 65536;
int base, mul, d, n, k, tc;
int bit[MOD + 5];

void add(int i, int val){
    while(i <= MOD){
        bit[i] += val;
        i += (i & -i);
    }
    return;
}

int sum(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= (i & -i);
    }
    return res;
}

int find(int i){
    int l = 1, r = MOD, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(sum(mid) < i)
            l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    for(int i = 1; i <= tc; i++){
        cin>>base>>mul>>d>>n>>k;
        memset(bit, 0, sizeof bit);

        int a[n + 1] = {0};
        a[1] = base;
        for(int i = 2; i <= n; i++)
            a[i] = (1LL * a[i - 1] * 1LL * mul + d) % MOD;

        for(int i = 1; i <= k; i++)
            add(a[i] + 1, 1);

        ll res = 0;
        int mid = (k + 1) / 2;
        for(int i = k + 1; i <= n; i++){
            res += find(mid) - 1;
            add(a[i - k] + 1, -1);
            add(a[i] + 1, 1);
        }
        res += find(mid) - 1;
        cout<<"Case #"<<i<<": "<<res<<el;
    }
    return 0;
}
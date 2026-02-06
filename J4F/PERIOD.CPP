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

int n, k, p, q, MOD;
const int maxn = 5e6 + 5;
ll a[maxn];

ll sub1(){
    ll minn = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        ll maxx = 0, d = k;
        for(int j = i; j <= n; j++){
            maxx = max(maxx, 1LL * a[j] + d);
            d += k;
        }
        for(int j = 1; j < i; j++){
            maxx = max(maxx, 1LL * a[j] + d);
            d += k;
        }

        minn = min(minn, maxx);
    }
    return minn;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>p>>q>>MOD;
    for(int i = 1; i <= n; i++)
        a[i] = (1LL * p * i) % MOD + q;

    ll d[2 * n + 1];
    for(int i = 1; i <= 2 * n; i++)
        d[i] = a[(i - 1) % n + 1] + 1LL * k * i;

    deque<int> dq;
    ll res = LLONG_MAX;
    for(int i = 1; i <= 2 * n; i++){
        while(!dq.empty() && d[dq.back()] <= d[i])
            dq.pop_back();
        dq.push_back(i);

        if(dq.front() < i - n + 1)
            dq.pop_front();

        if(i >= n){
            int tmp = i - n + 1;
            if(tmp <= n)
                res = min(res, d[dq.front()] - 1LL * k * tmp);
        }
    }
    cout<<res + k;
    return 0;
}
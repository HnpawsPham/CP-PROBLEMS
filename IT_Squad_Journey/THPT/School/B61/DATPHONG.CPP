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
#define taskname "DATPHONG"

struct hotel{
    int sz, val, w;
    hotel() {};
    hotel(int sz1, int val1, int w1): sz(sz1), val(val1), w(w1) {};

    bool operator<(const hotel& other){
        return val > other.val;
    }
};

int n, m;
vector<hotel> a;
vector<hotel> q;
const ll oo = 1e13 + 5;
const int maxroom = 1e5 + 5;

namespace sub1{
    bool checksub = 1;
    ll minn[maxroom], maxx[maxroom] = {0};

    void sol(){
        for(int i = 1; i < maxroom; i++){
            minn[i] = oo;
            maxx[i] = -oo;
        }

        minn[0] = maxx[0] = 0;
        for(int k = maxroom - 1; k > 0; k--)
            for(int i = 0; i < n; i++){
                if(a[i].sz <= k)
                    minn[k] = min(minn[k], minn[k - a[i].sz] + a[i].w);
            }

        for(int k = maxroom - 1; k > 0; k--)
            for(int i = 0; i < m; i++){
                if(q[i].sz <= k)
                    maxx[k] = max(maxx[k], maxx[k - q[i].sz] + q[i].w);
            }

        ll res = 0;
        for(int i = 0; i < maxroom; i++)
            res = max(res, maxx[i] - minn[i]);
        cout<<res;
    }
}

namespace sub2{
    ll dp[maxroom];

    void sol(){
        sort(a.begin(), a.end());
        sort(q.begin(), q.end());

        for(int i = 1; i < maxroom; i++)
            dp[i] = -oo;
        dp[0] = 0;

        int i = 0;
        for(int j = 0; j < m; j++){
            while(i < n && a[i].val >= q[j].val){
                for(int k = maxroom -3; k >= a[i].sz; k--)
                    dp[k] = max(dp[k], dp[k - a[i].sz] - a[i].w);
                i++;
            }

            for(int k = 0; k + q[j].sz < maxroom; k++)
                dp[k] = max(dp[k], dp[k + q[j].sz] + q[j].w);
        }
        cout<<*max_element(dp, dp + maxroom);
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++){
        int sz, val, w;
        cin>>sz>>val>>w;
        if(val != 1) sub1::checksub = 0;
        a.push_back({sz, val, w});
    }

    cin>>m;
    for(int i =0 ;i < m; i++){
        int sz, lim, pay;
        cin>>sz>>lim>>pay;
        if(lim != 1) sub1::checksub = 0;
        q.push_back({sz, lim, pay});
    }

    if(sub1::checksub)
        sub1::sol();
    else sub2::sol();
    return 0;
}
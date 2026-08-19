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
#define taskname "ROUNDNUM"

int n, k;
const int maxn = 205;
ll a[maxn];

pii pfact(ll x){
    int cnt2 = 0, cnt5 = 0;
    while(x > 0 && x % 2 == 0){
        x /= 2;
        cnt2++;
    }

    while(x > 0 && x % 5 == 0){
        x /= 5;
        cnt5++;
    }
    return {cnt2, cnt5};
}

namespace sub1{
    void sol(){
        int maxx = 0;
        for(const int& x : a){
            ll tmp = x;
            int cnt = 0;
            while(tmp > 0){
                cnt += (tmp % 10 == 0);
                tmp /= 10;
            }
            maxx = max(maxx, cnt);
        }
        cout<<maxx;
    }
}

pii p[maxn];

namespace sub2{
    void sol(){
        int cnt2 = 0, cnt5 = 0;
        for(int i = 0; i < n; i++){
            cnt2 += p[i].fi;
            cnt5 += p[i].se;
        }
        cout<<min(cnt2, cnt5);
    }
}

namespace sub3{
    int res = 0;

    void re(int i, int chosen, int cnt2, int cnt5){
        if(chosen == k){
            res = max(res, min(cnt2, cnt5));
            return;
        }
        if(i == n) return;

        re(i + 1, chosen + 1, cnt2 + p[i].fi, cnt5 + p[i].se);

        if(n - i >= k - chosen)
            re(i + 1, chosen, cnt2, cnt5);
    }

    void sol(){
        re(0, 0, 0 , 0);
        cout<<res;
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

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 0; i < n; i++)
        p[i] = pfact(a[i]);

    if(k == 1) sub1::sol();
    else if(k == n) sub2::sol();
    else sub3::sol();
    return 0;
}
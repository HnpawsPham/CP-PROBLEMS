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
#define taskname "CLIMBING"

int n, q;
const int maxn = 2e5 + 5;
int a[maxn];

namespace sub2{
    int dp[maxn][2]; //0: inc, 1 dec 

    void sol(){        
        while(q--){
            int l, r;
            cin>>l>>r;

            int res = 1;
            for(int i = l; i <= r; i++){
                dp[i][0] = 1;
                dp[i][1] = 0;

                for(int j = l; j < i; j++){
                    if(a[j] > a[i])
                        dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                    else if(a[j] < a[i])
                        dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
                if(dp[i][0] & 1) 
                    res = max(res, dp[i][0]);
            }
            cout<<res<<el;
        }
    }
}

namespace sub3{
    int t[maxn][2], sz;

    void add(int i, int val, int k){
        if(k){
            for(; i > 0; i -= (i & -i)) 
                t[i][k] = max(t[i][k], val);
        } else{
            for(; i <= sz; i += (i & -i)) 
                t[i][k] = max(t[i][k], val);
        }
    }

    int query(int i, int k){
        int res = 0;
        if(k){
            for(; i <= sz; i += (i & -i)) 
                res = max(res, t[i][k]);
        } else{
            for(; i > 0; i -= (i & -i)) 
                res = max(res, t[i][k]);
        }
        return res;
    }
    
    void clean(int i, int k){
        if(k){
            for(; i > 0; i -= (i & -i)) 
                t[i][k] = 0;
        } else{
            for(; i <= sz; i += (i & -i)) 
                t[i][k] = 0;
        }
    }

    int pos[maxn];
    void prep(){
        vi v;
        for(int i = 1; i <= n; i++) 
            v.push_back(a[i]);

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        sz = v.size();

        for(int i = 1; i <= n; i++)
            pos[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;

        memset(t, 0, sizeof t);
    }

    void sol(){
        prep();

        while(q--){
            int l, r;
            cin>>l>>r;

            int res = 1, dp0, dp1;
            for(int i = l; i <= r; i++){
                int q1 = query(pos[i] + 1, 1);
                dp0 = q1 + 1;
                add(pos[i], dp0, 0);

                int q0 = query(pos[i] - 1, 0);
                dp1 = q0 > 0 ? q0 + 1 : 0;
                add(pos[i], dp1, 1);
                

                if(dp0 & 1) res = max(res, dp0);
            }
            cout<<res<<el;

            for(int i = l; i <= r; i++){
                clean(pos[i], 1);
                clean(pos[i], 0);
            }
        }
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

    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];

    if(n <= 100 && q <= 100)
        sub2::sol();
    else if(n <= 2005 && q <= 2005) 
        sub3::sol();
    else cout<<"avoid tle"<<el;
    return 0;
}
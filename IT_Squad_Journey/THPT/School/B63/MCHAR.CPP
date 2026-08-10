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
#define taskname "MCHAR"

int n;
const int maxn = 5e4 + 15;
int a[maxn];

void sub2(){
    int dp[n + 1][4], res = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 4; j++)
            dp[i][j] = -maxn;

    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;

        for(int j = 0; j < i; j++){
            if(a[i] < a[j]){
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
                if(dp[j][0] >= 2) dp[i][1] = max(dp[i][1], dp[j][0] + 1);

                dp[i][3] = max(dp[i][3], dp[j][3] + 1);
                if(dp[j][2] >= 4) dp[i][3] = max(dp[i][3], dp[j][2] + 1);
            }
            else if(a[i] > a[j]){
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                dp[i][2] = max(dp[i][2], dp[j][2] + 1);
                if(dp[j][1] >= 3) dp[i][2] = max(dp[i][2], dp[j][1] + 1);
            }
        }
        res = max(res, dp[i][3]);
    }
    cout<<res;
}

namespace sub4{
    int t[maxn * 4][4];
    int m;
    
    void update(int i, int l, int r, int pos, int k, int val){
        if(l == r){
            t[i][k] = val;
            return;
        }

        int mid = (l + r) / 2;
        if(pos <= mid) update(2 * i, l, mid, pos, k, val);
        else update(2 * i + 1, mid + 1, r, pos, k, val);
        t[i][k] = max(t[2 * i][k], t[2 * i + 1][k]);
    }

    int query(int i, int st, int en, int l, int r, int k){
        if(st > r || en < l) return -maxn;
        if(st >= l && en <= r) return t[i][k];

        int mid = (st + en) / 2;
        return max(query(2 * i, st, mid, l, r, k), query(2 * i + 1, mid + 1, en, l, r, k));
    }

    int query(int l, int r, int k){
        if(l > r) return -maxn;
        return query(1, 1, m, l, r, k);
    }

    void sol(){
        int res = 0;
        for(int i = 0; i < 4 * maxn; i++)
            for(int j = 0; j < 4; j++)
                t[i][j] = -maxn;

        vi mp = {-1};
        for(int i = 1; i <= n; i++)
            mp.push_back(a[i]);

        sort(mp.begin(), mp.end());
        mp.erase(unique(mp.begin(), mp.end()), mp.end());
        m = mp.size();

        for(int i = 1; i <= n; i++){
            int pos = lower_bound(mp.begin(), mp.end(), a[i]) - mp.begin();
            int dp0 = 1, dp1 = 0, dp2 = 0, dp3 = 0;

            // ai < aj
            dp1 = max(dp1, query(pos + 1, m, 1) + 1);
            dp3 = max(dp3, query(pos + 1, m, 3) + 1);

            int q0 = query(pos + 1, m, 0);
            if(q0 >= 2) dp1 = max(dp1, q0 + 1);

            int q2 = query(pos + 1, m, 2);
            if(q2 >= 4) dp3 = max(dp3, q2 + 1);

            // ai > aj
            dp0 = max(dp0, query(1, pos - 1, 0) + 1);
            dp2 = max(dp2, query(1, pos - 1, 2) + 1);

            int q1 = query(1, pos - 1, 1);
            if(q1 >= 3) dp2 = max(dp2, q1 + 1);

            update(1, 1, m, pos, 0, dp0);
            if(dp1 > 0) update(1, 1, m, pos, 1, dp1);
            if(dp2 > 0) update(1, 1, m, pos, 2, dp2);
            if(dp3 > 0) update(1, 1, m, pos, 3, dp3);

            res = max(res, dp3);
        }
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

    cin>>n;
    memset(a, 0, sizeof a);
    for(int i = 1; i <= n; i++) cin>>a[i];

    if(n <= 3162) sub2();
    else sub4::sol();
    // sub4::sol();
    return 0;
}
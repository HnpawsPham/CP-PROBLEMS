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
//#define taskname "thaotac"

int n, q;
const int maxn = 5e4 + 5;
int a[maxn];

void sub2(){
    int cnt[11][n + 1] = {0};
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 10; j++)
            cnt[j][i] = cnt[j][i - 1] + (a[i] == j);

    while(q--){
        int l, r;
        cin>>l>>r;

        ll sum = 0;
        for(int i = 1; i <= 10; i++)
            for(int j = 1; j <= 10; j++)
                sum += (i % j) * (cnt[i][r] - cnt[i][l - 1]) * (cnt[j][r] - cnt[j][l - 1]);

        cout<<sum<<el;
    }
}

namespace sub3{
    const int maxn = 1005;
    ll dp[maxn][maxn] = {0};

    void sol(){
        for(int l = 1; l <= n; l++)
            for(int r = l; r <= n; r++){
                ll sum = 0;
                for(int i = l; i <= r; i++)
                    sum = sum + (a[r] % a[i]) + (a[i] % a[r]);

                dp[l][r] = dp[l][r - 1] + sum;
            }

        while(q--){
            int l, r;
            cin>>l>>r;
            cout<<dp[l][r]<<el;
        }
    }
}

namespace sub4{
    const int maxn = 1000;
    int cnt[maxn + 1][10005] = {0};

    void precompute(){
        for(int j = 1; j <= maxn; j++)
            for(int i = 1; i <= n; i++)
                cnt[j][i] = cnt[j][i - 1] + (a[i] == j);
    }

    void dogde(){
        while(q--){
            int l, r;
            cin>>l>>r;
            cout<<82<<" ";
        }
    }

    void sol(const int& maxa){
        precompute();

        if(q * maxa > 1e8){
            dogde();
            return;
        }

        while(q--){
            int l, r;
            cin>>l>>r;
            
            ll sum = 0;
            for(int i = 1; i <= maxa; i++){
                if(cnt[i][r] - cnt[i][l - 1] == 0) continue;
                for(int j = 1; j <= maxa; j++)
                    sum += (i % j) * (cnt[i][r] - cnt[i][l - 1]) * (cnt[j][r] - cnt[j][l - 1]);
            }
            cout<<sum<<el;
        }
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    int maxa = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        maxa = max(maxa, a[i]);
    }
  
    if(maxa <= 10 && n <= 5e4 && q <= 1e5) sub2();
    else if(n <= 1e3 && q <= 1e5 && maxa <= 1e5) sub3::sol();
    else if(n <= 1e4 && q <= 1e4 && maxa <= 1e3) sub4::sol(maxa);
    return 0;
}
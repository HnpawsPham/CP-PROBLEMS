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
#define taskname "SMM"

int n, q;
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;
string s;

namespace sub2{
    const int maxa = 2e6 + 6;
    int p[maxa] = {0};

    bool check(int x){
        int prev = -1;
        while(x > 0){
            if(x % 10 == 1 && prev == 3)   
                return 0;
            prev = x % 10;
            x /= 10;
        }
        return 1;
    }

    void prepare(){
        p[0] = 1;
        for(int i = 1; i < maxa; i++)
            p[i] = (p[i - 1] + check(i)) % MOD;
    }

    void sol(){
        prepare();

        while(q--){
            int opt; 
            cin>>opt;

            if(opt == 1){
                int l, r;
                cin>>l>>r;
                
                int numr = 0, numl = 0;
                for(int i = l; i <= r; i++)
                    numr = numr * 10 + (s[i - 1] - '0');
                cout<<p[numr] % MOD<<el;
            }
            else{
                int pos;
                char val;
                cin>>pos>>val;
                s[pos - 1] = val;
            }
        }
    }
} 

namespace sub3{
    ll dp[2005][2][11]; //n, less, prev
    string lim;

    ll dfs(int i, bool less, int prev){
        if(i == lim.length()) return 1;

        if(dp[i][less][prev + 1] != -1)
            return dp[i][less][prev + 1];

        ll res = 0;
        int maxx = 9;
        if(!less) maxx = lim[i] - '0';

        for(int j = 0; j <= maxx; j++){
            if(prev == 1 && j == 3) continue;
            res = (res + dfs(i + 1, (less || j < maxx) ,j)) % MOD;
        }
        return dp[i][less][prev + 1] = res;
    }

    void sol(){
        while(q--){
            int opt; 
            cin>>opt;

            if(opt == 1){
                int l, r;
                cin>>l>>r;
                
                memset(dp, -1, sizeof dp);
                lim = s.substr(l - 1, r - l + 1);
                cout<<dfs(0, 0, -1)<<el;
            }
            else{
                int pos;
                char val;
                cin>>pos>>val;
                s[pos - 1] = val;
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

    cin>>n>>q>>s;
    
    if(n <= 6)
        sub2::sol();
    else sub3::sol();
    return 0;
}
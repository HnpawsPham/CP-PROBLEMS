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

int tc = 1;
const int maxp = 1500;
bitset<maxp> nprime;

void sieve(){

    nprime[0] = nprime[1] = 1;

    for(int i = 2; i * i < maxp; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxp; j+=i)
                nprime[j] = 1;
    return;
}

string lim;
ll dp[20][165][maxp];

ll dfs(int i, bool less, int sumd, int sump){
    if(i == lim.size()){
        if(!nprime[sumd] && !nprime[sump]) 
            return 1;
        return 0;
    }

    int remain = lim.size() - i;
    if(less && dp[remain][sumd][sump] != -1)
        return dp[remain][sumd][sump];

    int maxx = 9;
    if(!less) maxx = lim[i] - '0';

    ll res = 0;
    for(int j = 0; j <= maxx; j++)
        res += dfs(i + 1, less || j < maxx, sumd + j, sump + j * j);
    
    if(less) dp[remain][sumd][sump] = res;
    return res;
}

ll sol(ll x){
    lim = to_string(x);
    return dfs(0, 0, 0, 0);
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
    sieve();
    memset(dp, -1, sizeof dp);

    while(tc--){
        ll a, b;
        cin>>a>>b;
        cout<<sol(b) - sol(a - 1)<<el;
    }
    return 0;
}
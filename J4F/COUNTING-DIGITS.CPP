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

vll dp[10][2][2]; //st less 0-9
string lim = "";

vll dfs(int i, bool st, bool less){
    if(i == lim.length())
        return vll(10, 0);

    if(dp[i][st][less][0] != -1)
        return dp[i][st][less];

    int maxx = less ? 9 : lim[i] - '0';

    vll res(10, 0);
    for(int j = 0; j <= maxx; j++){
        vll tmp = dfs(i + 1, st || j > 0, less || j < maxx);

        for(int k = 0; k < 10; k++)
            res[k] += tmp[k];

        if(st || j > 0){
            ll cnt = 1;
            if(less || j < maxx){
                for(int k = i + 1; k < lim.length(); k++)
                    cnt *= 10;
            }
            else{
                string left = lim.substr(i + 1);
                cnt = (left.empty() ? 0 : stoi(left)) + 1;
            }
            res[j] += cnt;
        }
    }
    return dp[i][st][less] = res; 
}

vll sol(int x){
    lim = to_string(x); 

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 2; j++)
            for(int z = 0; z < 2; z++)
                dp[i][j][z].assign(10, -1);

    return dfs(0, 0, 0);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    while(1){
        cin>>a>>b;
        if(a == 0 && b== 0) break;
        if(a > b) swap(a, b);
        
        vll r = sol(b);
        vll l = sol(a - 1);
        for(int i = 0; i < 10; i++)
            cout<<r[i] - l[i]<<" ";
        cout<<el;
    }
    return 0;
}
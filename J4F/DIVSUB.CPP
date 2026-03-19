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

int n, MOD;
string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>MOD>>s;

    if(MOD == 2 || MOD == 5){
        ll cnt = 0;
        for(int i = 0; i < n; i++)
            if((s[i] - '0') % MOD == 0)
                cnt += i + 1;

        return cout<<cnt, 0;
    }

    int mp[MOD] = {0};
    mp[0] = 1;
    
    int mul = 1, cur = 0;
    ll cnt = 0;

    for(int i = n - 1; i >= 0; i--){
        cur = (cur + int(s[i] - '0') * mul) % MOD;
        cnt += mp[cur];
        mp[cur]++;
        mul = mul * 10 % MOD;
    }
    cout<<cnt;
    return 0;
}
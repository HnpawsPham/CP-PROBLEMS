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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;
    int cnt0[n + 1] = {0}, cnt1[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        cnt0[i] = cnt0[i - 1] + (s[i - 1] == '0');
        cnt1[i] = cnt1[i - 1] + (s[i - 1] == '1');
    }

    unordered_map<int, int> mp;
    mp[0] = 0;
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(mp.find(cnt1[i] - cnt0[i]) != mp.end())
            res = max(res, i - mp[cnt1[i] - cnt0[i]]);
        else mp[cnt1[i] - cnt0[i]] = i;
    }
    cout<<res;
    return 0;
}
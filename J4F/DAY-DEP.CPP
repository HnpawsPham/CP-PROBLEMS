#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define fi first
#define se second

int n;

int main(){
    freopen("DAYDEP.INP", "r", stdin);
    freopen("DAYDEP.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    unordered_map<int, int> mp;
    while(n--){
        int x;
        cin>>x;
        mp[x]++;
    }
    
    int cnt = 0;
    for(const auto x : mp){
        if(x.se < x.fi) cnt += x.se;
        else if(x.se > x.fi) cnt += (x.se - x.fi);
    }
    cout<<cnt;
    return 0;
}
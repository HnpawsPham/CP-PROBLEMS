#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<ll, int>

int n;
unordered_map<ll, int> mp;

int main(){
    freopen("SALES.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(n--){
        ll x; cin>>x;
        mp[x]++;
    }

    int cnt = 0;
    for(pii x : mp){    
        int freq = x.second;

        if(freq < 2 || freq % 3 == 1 && freq < 4) return cout<<-1, 0;
        
        if(freq % 3 == 0) cnt += freq / 3;
        else if(freq % 3 == 1) cnt += (freq / 3 - 1) + 2;
        else cnt += freq / 3 + 1;
    }
    cout<<cnt;

    return 0;
}
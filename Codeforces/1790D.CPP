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

int sol(){
    int n;
    cin>>n;

    map<int, int> mp;
    while(n--){
        int x;
        cin>>x;
        mp[x]++;
    }

    ll res = 0;
    int prev = 0, last = -1;
    for(auto [x, cnt] : mp){
        if(last != -1 && last != x - 1)
            prev = 0;

        res += max(0, cnt - prev);
        prev = cnt; 
        last = x;
    }
    return res;
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
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}
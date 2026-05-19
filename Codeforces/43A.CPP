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
    cin>>n;
    unordered_map<string, int> mp;
    while(n--){
        string s;
        cin>>s;
        mp[s]++;
    }

    string res;
    int maxx = 0;
    for(auto x : mp)
        if(x.se > maxx){
            maxx = x.se;
            res = x.fi;
        }
    cout<<res;
    return 0;
}
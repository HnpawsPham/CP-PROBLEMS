#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using bigl = __int128_t;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

void print(bigl x){
    if(x == 0){
        cout<<0;
        return;
    }

    string s = "";
    while(x > 0){
        s.push_back((x % 10) + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout<<s;
}

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
    unordered_map<string, ll> mp;
    while(n--){
        string s;
        ll x;
        cin>>s>>x;
        if(mp.count(s))
            mp[s] = min(mp[s], x);
        else mp[s] = x;
    }

    bigl res = 0;
    for(const auto& x : mp)
        res += x.se;
    cout<<mp.size()<<" ";
    print(res);
    return 0;
}
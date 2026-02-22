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

ll sol(){
    int n;
    string s;
    cin>>n>>s;

    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    ll res = 0;

    for(int i = 1; i <= n; i++){
        sum += int(s[i - 1] - '0');

        res += mp[sum - i];
        mp[sum - i]++;
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
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

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<int, int> mp;
    int minn[n + 1];

    int sum = 0, res = n + 5;
    mp[0] = 1;
    minn[0] = n + 5;

    for(int i = 1; i <= n; i++){
        sum += a[i - 1];
        minn[i] = minn[i - 1];
        int x = sum - k;

        if(mp.find(x) != mp.end()){
            res = min(res, i - mp[x] + minn[mp[x]]);
            minn[i] = min(minn[i], i - mp[x]);
        }
        mp[sum] = i;
    }
    cout<<(res > n ? -1 : res);
    return 0;
}

// 5 3
// 3 2 2 4 3

// 4 7
// 7 3 4 7
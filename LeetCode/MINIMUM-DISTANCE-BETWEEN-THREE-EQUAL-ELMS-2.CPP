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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<int, vi> mp;
    int minn = n * 3;
    for(int i = 0; i < n; i++){
        int sz = mp[a[i]].size();
        if(sz >= 2) 
            minn = min(minn, 2 * i - 2 * mp[a[i]][sz - 2]);
        mp[a[i]].push_back(i);
    }
    cout<<(minn == n * 3 ? -1 : minn);
    return 0;
}

// 5
// 1 2 1 1 3

// 7
// 1 1 2 3 2 1 2
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
    vll res(n, 0);
    for(int i = 0; i < n; i++)
        mp[a[i]].push_back(i);

    if(mp[a[0]] == n){
        for(int i = 0; i < n; i++)
            res[i] = i * (i + 1) / 2 + (n - i - 1) * (n - i) / 2;
    }
    else{
        for(int i = 0; i < n; i++)
            for(int j : mp[a[i]])
                res[j] += abs(i - j);
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 5
// 1 3 1 1 2
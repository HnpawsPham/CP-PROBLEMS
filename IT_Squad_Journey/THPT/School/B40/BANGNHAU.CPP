#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    // freopen("BANGNHAU.INP", "r", stdin);
    // freopen("BANGNHAU.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    int a[n];
    unordered_map<int, int> mp;
    for(int i= 0; i < n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    int f = 0, v;
    for(auto x : mp)
        if(x.se > f){
            f = x.se;
            v = x.fi;
        }
    cout<<f<<" "<<v;
    return 0;
}

// 8
// 3 1 4 1 -2 4 0 7

// 5
// 4 2 18 7 3
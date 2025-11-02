#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
ll a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b;
    int v[n];
    for(int i = 0; i < n; i++) cin>>v[i];

    unordered_map<int, int> mp;
    for(int x : v) mp[x]++;

    int gr1 = 0, gr2 = 0;
    for(auto x : mp){
        if(x.se == 1) gr1++;
        else gr2++;
    }
    cout<<1LL * ((gr1 + 1) / 2) * (a + b) + 1LL * ((gr2 + (gr1 % 2)) / 2) * b;
    return 0;
}

// 8 1 1
// 4 2 1 3 5 1 2 1
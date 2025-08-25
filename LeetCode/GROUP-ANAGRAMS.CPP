#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define vs vector<string>
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vs a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    map<vi, vs> res;
    for(string s : a){
        vi cnt(26, 0);
        for(char x : s) cnt[x - 'a']++;
        res[cnt].push_back(s);
    }
    for(auto v : res){
        for(auto x : v.se) cout<<x<<" ";
        cout<<el;
    }
    return 0;
}

// 6
// eat tea tan ate nat bat
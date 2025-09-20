#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    unordered_set<int> s[n + 1];
    vi res;
    while(k--){
        int x, y;
        cin>>x>>y;
        s[x].insert(y);
        if(s[x].size() == m) res.push_back(x);
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}
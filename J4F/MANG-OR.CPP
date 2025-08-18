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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_set<ll> res, cur, tmp;
    for(const ll& x : a){
        tmp.insert(x);

        for(const ll& y : cur)
            tmp.insert(y | x);
        
        cur = tmp;
        res.insert(cur.begin(), cur.end());
        tmp.clear();
    }
    cout<<res.size();
    return 0;
}
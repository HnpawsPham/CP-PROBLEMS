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
const int maxn = 2e5 + 5;
int a[maxn], c[maxn];
ll dp[maxn];

struct CHT{
    vector<pii> v;
    int id = 0;
    bool check(pii a,pii b,pii c){
        return (b.se - a.se) * (a.fi - c.fi) >= (c.se - a.se) * (a.fi - b.fi);
    }

    ll calc(pii y,int x){
        return y.fi * x + y.se;
    }

    void add(pii x){
        while(v.size() > 1 && check(v[v.size() - 2], v[v.size() - 1], x)) 
            v.pop_back();
        v.push_back(x);
    }
    
    ll get(int x){
        if(id > v.size() - 1) id = v.size() -1;
        while(id < v.size() -1 && id > 0 && calc(v[id], x) >= calc(v[id + 1], x)) id++;
        return calc(v[id], x);
    }
} hull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>c[i];
    
    for(int i = 2; i <= n; i++){
        hull.add({c[i - 1], dp[i - 1]});
        dp[i] = hull.get(a[i]);
    }
    cout<<dp[n];
    return 0;
}
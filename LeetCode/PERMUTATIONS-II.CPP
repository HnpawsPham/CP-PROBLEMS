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
vector<vi> res;
bitset<9> check;

void sol(int st, vi v, const vi& a){
    if(st == n){
        res.push_back(v);
        return;
    }

    for(int i = 0; i < n; i++){
        if(check[i]) continue;
        if(i > 0 && a[i] == a[i - 1] && !check[i - 1]) continue;

        check[i] = 1;
        v.push_back(a[i]);
        sol(st + 1, v, a);
        v.pop_back();
        check[i] = 0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    sol(0, {}, a);
    for(auto v : res){
        for(int x : v) cout<<x<<" ";
        cout<<el;
    }
    return 0;
}
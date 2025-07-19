#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>m;
    int a[m];
    for(int i = 0; i < m; i++) cin>>a[i];

    int n = m / 3;
    priority_queue<int, vi> l;
    priority_queue<int, vi, greater<int>> r;
    vector<ll> lp(n + 1);

    ll sum = 0;

    for(int i = 0; i < n; i++){
        sum += a[i];
        l.push(a[i]);
    }
    lp[0] = sum;

    for(int i = n; i < 2 * n; i++){
        sum += a[i];
        l.push(a[i]);
        
        sum -= l.top();
        l.pop();
        lp[i - n + 1] = sum;
    }
    sum = 0;

    for(int i = n * 3 - 1; i >= n * 2; i--){
        sum += a[i];
        r.push(a[i]);
    }

    ll res = lp[n] - sum;

    for(int i = n * 2 - 1; i >= n; i--){
        sum += a[i];
        r.push(a[i]);
        
        sum -= r.top();
        r.pop();
        res = min(res, lp[i - n] - sum);
    }
    cout<<res;
    return 0;
}
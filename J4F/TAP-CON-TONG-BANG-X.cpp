#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, cnt = 0;
ll x;
ll a[45];

void solve(int i, ll sum){
    if(sum > x) return;
    if(i >= n){
        if(sum == x) cnt++;
        return;
    }

    solve(i + 1, sum + a[i]);
    solve(i + 1, sum);
    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x;
    for(int i = 0; i < n; i++) cin>>a[i];

    solve(0, 0);
    cout<<cnt;

    return 0;
}
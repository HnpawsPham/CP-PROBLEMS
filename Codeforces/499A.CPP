#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x;
    pii a[n];
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;

    int pos = 1;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        pos += (a[i].fi - pos) / x * x;
        cnt += (a[i].se - pos + 1);
        pos = a[i].se + 1;
    }
    cout<<cnt;
    return 0;
}
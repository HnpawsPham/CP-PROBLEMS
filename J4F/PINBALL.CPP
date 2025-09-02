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

    ll n, k;
    cin>>n>>k;

    if(k < n) cout<<k + 1;
    else{
        if(k % 2) cout<<2 * n - k - 1;
        else cout<<2 * n - k - 3;
    }
    return 0;
}
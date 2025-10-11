#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;

ll sol(){
    ll n, k;
    cin>>n>>k;

    if(n == 1) return 0;
    ll cnt = 1, t = 0;

    while(cnt < n && cnt < k){
        cnt *= 2;
        t++;
    }

    if(cnt < n) t += (n - cnt + k - 1) / k;
    return t;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}
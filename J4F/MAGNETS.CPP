#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, n;
const int maxn = 2e5 + 5;
db a[maxn];

db naive(){
    db res = 0;
    while(1){
        db maxx = 0;
        for(int i = 1; i < n; i++){
            db t = (a[i] - a[i - 1]) / 2.0;
            maxx = max(maxx, t);
            res += t;
            a[i] -= t;
            a[i - 1] += t;
        }
        if(maxx == 0) break;
    }
    return res;
}

db sol(){
    db res = 0;
    for(int i = 1; i < n; ++i) 
        res += (a[i] - a[i-1]) * i * (n - i);
    return res / 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i = 0; i < n; i++) cin>>a[i];

        cout<<fixed<<setprecision(6);
        cout<<sol()<<el;
        // if(n <= 100) cout<<naive()<<el;
        // else cout<<sol()<<el;
    }
    return 0;
}
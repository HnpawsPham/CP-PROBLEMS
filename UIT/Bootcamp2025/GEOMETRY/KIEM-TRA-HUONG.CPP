#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;
ll xa, xb, xc, ya, yb, yc;

string sol(){
    cin>>xa>>ya>>xb>>yb>>xc>>yc;

    ll s = 1LL * (xb - xa) * (yc - ya) - 1LL * (xc - xa) * (yb - ya);
    if(s > 0) return "LEFT";
    else if(s < 0) return "RIGHT";
    return "TOUCH";
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
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

    db x, y;
    cin>>x>>y;
    db res = atan2(y, x);
    if(res < 0) res += 2 * M_PI;

    cout<<fixed<<setprecision(7)<<res;
    return 0;
}
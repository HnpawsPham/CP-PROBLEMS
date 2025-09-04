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

    int x, y, z;
    cin>>x>>y>>z;

    int d1 = abs(x - z), d2 = abs(y - z);
    if(d1 == d2) cout<<0;
    else if(d1 < d2) cout<<1;
    else cout<<2;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

db x, y, a, b, c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>x>>y>>a>>b>>c;
    cout<<fixed<<setprecision(7)<<fabs(a * x + b * y + c) / sqrt(a * a + b * b);
    return 0;
}
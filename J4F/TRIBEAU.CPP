#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll a, b, c, d;

bool valid(ll x, ll y){
    return abs(x - y) <= d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c>>d;
    if(valid(a, b) && valid(b, c) && valid(a, c)) cout<<"Yes";
    else cout<<"No";

    return 0;
}
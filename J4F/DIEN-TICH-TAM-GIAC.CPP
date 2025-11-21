#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll u, v;
    cin>>u>>v;
    ll d = u * u + v * v;
    cout<<d / 4;
    if(d % 4 == 0) cout<<".00";
    else if(d % 4 == 1) cout<<".25";
    else if(d % 4 == 2) cout<<".50";
    else cout<<".75";
    return 0;
}

// 2 4
// 3 7
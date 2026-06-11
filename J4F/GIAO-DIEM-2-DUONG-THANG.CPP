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
//#define taskname ""

struct line{
    ll a, b, c;
    line() {};
};

db calc(ll a, ll b, ll c, ll d){
    return a * b - c * d;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    line l1, l2;
    cin>>l1.a>>l1.b>>l1.c;
    cin>>l2.a>>l2.b>>l2.c;

    db d = calc(l1.a, l2.b, l2.a, l1.b);
    db dx = calc(l1.b, l2.c, l2.b, l1.c);
    db dy = calc(l1.c, l2.a, l1.a, l2.c);

    cout<<fixed<<setprecision(6)<<dx / d<<" "<<dy / d;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define el "\n"
using ll = long long;

int n;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

int main(){
    freopen(".\\txt\\PHANSO.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    ll tu = 0, mau = 1;

    for(int i = 0;i<n;i++){
        ll x, y;
        cin>>x>>y;
        tu = mau * x + tu * y;
        mau *= y; 

        ll gcdd = gcd(mau, tu);
        tu /= gcdd;
        mau /= gcdd;
    }

    if(tu % mau == 0) cout<<tu / mau;
    else if(tu > mau) cout<<tu / mau<<" "<<tu % mau<<" "<<mau;
    else cout<<tu<<" "<<mau;

    return 0;
}
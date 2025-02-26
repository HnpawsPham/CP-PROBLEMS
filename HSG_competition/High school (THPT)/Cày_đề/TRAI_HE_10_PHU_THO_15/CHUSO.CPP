#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

string str;
int n; ll m, len1;

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b % 2 == 0) return half * half;
    return half * half * a;
}

int main(){
    freopen("CHUSO.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    cin>>n>>m;
    string a1 = str;
    reverse(str.begin(), str.end());
    a1 += str;

    len1 = a1.length();
    
    if(m <= len1 * ppow(2, n - 1))
        cout<<(a1[(m % len1 != 0) ? (m % len1) - 1 : len1 - 1]);
    else cout<<-1;
    
    return 0;
}
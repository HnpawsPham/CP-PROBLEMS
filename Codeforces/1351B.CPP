#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

string sol(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(b < a) swap(a, b);
    if(d < c) swap(c, d);

    if((a == c && b + d == c) || (b == d && a + c == d)) return "Yes";
    return "No";
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
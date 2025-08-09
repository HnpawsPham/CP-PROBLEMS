#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, a, b, c;

char sol(){
    if(a + b == c) return '+';
    return '-';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cout<<sol()<<el;
    }

    return 0;
}
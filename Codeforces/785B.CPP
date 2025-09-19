#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int oo = INT_MAX;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n;
    int ar = oo, al = 0, bl = 0, br = oo;
    for(int i = 0; i < n; i++){
        int l, r;
        cin>>l>>r;
        ar = min(ar, r);
        al = max(al, l);
    }
    cin>>m;
    for(int i = 0; i < m; i++){
        int l, r;
        cin>>l>>r;
        br = min(br, r);
        bl = max(bl, l);
    }
    cout<<max({0, bl - ar, al - br});
    return 0;
}
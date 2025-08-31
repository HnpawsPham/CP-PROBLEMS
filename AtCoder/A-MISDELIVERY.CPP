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

    int n, x;
    string y;
    cin>>n;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    cin>>x>>y;
    if(a[x - 1] == y) cout<<"Yes";
    else cout<<"No";
    return 0;
}
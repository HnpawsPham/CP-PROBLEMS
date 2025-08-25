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

    int n, m, a;
    cin>>n>>m>>a;
    cout<<1LL * ((n + a - 1) / a) * ((m + a - 1) / a);
    return 0;
}
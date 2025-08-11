#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++){
        ll res = 1LL * i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2);
        cout<<res<<el;
    }

    return 0;
}
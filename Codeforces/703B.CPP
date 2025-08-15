#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n + 1];
    bool cap[n + 1] = {0};
    ll res = 0, sum = 0;

    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        sum += a[i];
    }

    while(k--){
        int x;
        cin>>x;
        cap[x] = 1;
        res += a[x] * (sum - a[x]);
        sum -= a[x];
    }

    for(int i = 1; i <= n; i++)
        if(!cap[i] && !cap[(i % n) + 1])
            res += a[i] * a[(i % n) + 1];
            
    cout<<res;
    return 0;
}
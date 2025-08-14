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

    int n;
    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    ll res = LLONG_MIN;
    unordered_map<int, ll> minpl;

    for(int i = 1; i <= n; i++){
        if(minpl.count(a[i])){
            res = max(res, p[i] - minpl[a[i]]);
            minpl[a[i]] = min(minpl[a[i]], p[ i -1]);
        }
        else minpl[a[i]] = p[i - 1];
    }
    cout<<res;
    return 0;
}

// 7
// 3 3 3 3 1 11 1
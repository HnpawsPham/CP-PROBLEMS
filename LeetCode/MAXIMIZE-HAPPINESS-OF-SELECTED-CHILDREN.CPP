#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end(), greater<int>());

    ll sum;
    for(int i = 0; i < k; i++)
        if(a[i] - i >= 0) sum += 1LL * a[i] - i;
        else break;
    cout<<sum;
    return 0;
}

// 3 2
// 1 2 3

// 4 2
// 1 1 1 1
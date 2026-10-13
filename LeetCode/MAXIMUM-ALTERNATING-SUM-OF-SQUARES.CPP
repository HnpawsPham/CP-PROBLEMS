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

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int& x: a) x = abs(x);
    sort(a.begin(), a.end(), greater<int>());

    ll sum = 0;
    int i =0 , r = n - 1;
    for(; i < r; i++){
        sum += 1LL * a[i] * a[i] - 1LL * a[r] * a[r];
        r--;
    }
    if(r == i) sum += 1LL * a[r] * a[r];
    cout<<sum;
    return 0;
}

// 3
// 1 2 3 

// 6
// 1 -1 2 -2 3 -3
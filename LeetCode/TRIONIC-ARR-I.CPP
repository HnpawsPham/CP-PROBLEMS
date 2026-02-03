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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int i = 1, p, q;
    while(i < n && a[i - 1] < a[i]) i++;
    p = i - 1;

    while(i < n && a[i - 1] > a[i]) i++;
    q = i - 1;

    while(i < n && a[i - 1] < a[i]) i++;
    
    if(0 < p && p < q && q < n - 1 && i == n) cout<<1;
    else cout<<0;
    return 0;
}

// 6
// 1 3 5 4 2 6

// 3
// 2 1 3
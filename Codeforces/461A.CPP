#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
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
    for(int i = 0 ; i < n; i++) cin>>a[i];

    if(n == 1) return cout<<a[0], 0;
    sort(a, a + n, greater<int>());

    int k = n;
    ll sum = 1LL * a[0] * k;
    for(int i = 1; i < n; i++){
        sum += 1LL * a[i] * 1LL * k;
        k--;
    }
    cout<<sum;
    return 0;
}
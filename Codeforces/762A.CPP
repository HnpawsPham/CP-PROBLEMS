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

    ll n, k;
    cin>>n>>k;
    vll a;
    a.push_back(1);
    if(n != 1) a.push_back(n);
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0){
            a.push_back(i);
            if(i != n / i) a.push_back(n / i);
        }
    sort(a.begin(), a.end());

    if(a.size() < k) cout<<-1;
    else cout<<a[k - 1];
    return 0;
}
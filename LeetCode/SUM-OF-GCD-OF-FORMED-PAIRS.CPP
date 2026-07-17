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

    int maxx = 0;
    vector<int> res;
    for(const int& x : a){
        maxx = max(maxx, x);
        res.push_back(__gcd(x, maxx));
    }
    sort(res.begin(), res.end());

    ll sum = 0;
    for(int i = 0; i < n / 2; i++)
        sum += __gcd(res[i], res[n - i - 1]);
    cout<<sum;
    return 0;
}
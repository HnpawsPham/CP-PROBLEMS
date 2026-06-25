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
    ll sum = 0;
    while(n--){
        int a, b;
        cin>>a>>b;
        sum += 1LL * b * 1LL* (b + 1) / 2LL - 1LL * a * 1LL * (a - 1) / 2LL;
    }
    cout<<sum;
    return 0;
}
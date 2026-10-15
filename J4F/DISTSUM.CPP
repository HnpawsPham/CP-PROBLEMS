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

int n;
const int maxn = 1e5 + 5;
int x[maxn], y[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i =0 ; i < n; i++) 
        cin>>x[i]>>y[i];

    sort(x, x + n);
    sort(y, y + n);

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += x[i] * (2LL * i - n + 1);
        sum += y[i] * (2LL * i - n + 1);
    }
    cout<<sum;
    return 0;
}
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

int n, m;
const int maxn = 2e5 + 5;
ll a[maxn], b[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i > 0) a[i] += a[i - 1];
    }

    for(int i = 0; i < m; i++) cin>>b[i];

    int pos = 0;
    for(int i = 0; i < m; i++){
        while(a[pos] < b[i]) pos++;
        cout<<pos + 1<<" "<<b[i] - (pos > 0 ? a[pos - 1] : 0)<<el;
    }
    return 0;
}
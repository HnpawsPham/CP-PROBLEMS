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
int a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = -1;
    ll t = 1e15 + 5;
    for(int i = 0; i < n; i++){
        int round = (max(0, a[i] - i) + n - 1) / n;
        if(round * n + i < t){
            t = round * n + i;
            res = i + 1;
        }
    }
    cout<<res;
    return 0;
}
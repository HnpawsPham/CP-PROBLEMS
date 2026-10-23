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

int n, m, k;
const int oo = 1e6 + 6;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    int minn[m];
    for(int i = 0; i < m; i++)
        minn[i] = oo;

    for(int i = 0; i < n; i++){
        int pos, val;
        cin>>pos>>val;
        minn[pos - 1] = min(minn[pos - 1], val);
    }
    
    int res = 0;
    for(int i= 0; i < m; i++)
        res += minn[i];
    cout<<min(res, k);
    return 0;
}
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
const int maxn = 1e5 + 5;
bool checkrow[maxn], checkcol[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
 
    memset(checkrow, 0, sizeof checkrow);
    memset(checkcol, 0, sizeof checkcol);

    ll sum = 1LL * n * n;
    int r = n, c = n;
    while(m--){
        int x, y;
        cin>>x>>y;
        if(!checkcol[x]){
            checkcol[x] = 1;
            sum -= r;
            c--;
        }
        if(!checkrow[y]){
            checkrow[y] = 1;
            sum -= c;
            r--;
        }
        cout<<sum<<" ";
    }
    return 0;
}
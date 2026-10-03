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
const int maxn = 1e6 + 5;
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
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++) cin>>a[i];

    int dp = 1, res = 1;
    for(int i = 1; i < n; i++)
        if(a[i - 1] < a[i]){
            dp++;
            res = max(res, dp);
        }
        else dp = 1;
        
    cout<<res;
    return 0;
}
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
    for(int i = 0; i< n; i++) cin>>a[i];
    
    int cnt = 1, res = 0, prev = 0;
    for(int i = 1; i < n; i++)
        if(a[i] == a[i - 1]) cnt++;
        else{
            res = max(res, 2 * min(prev, cnt));
            prev = cnt;
            cnt = 1;
        }
    cout<<max(res, 2 * min(prev, cnt));
    return 0;
}
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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int minn = *min_element(a, a + n);
    int res = n + 1, prev = -1;
 
    for(int i = 0; i < n; i++){
        if(a[i] != minn) continue;
        if(prev != -1) 
            res = min(res, i - prev);
        prev = i;
    }
    cout<<res;
    return 0;
}
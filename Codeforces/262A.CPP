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

    int n, k, x;
    cin>>n>>k;
    int res = 0;
    while(n--){
        cin>>x;
        int cnt = 0;
        while(x > 0){
            cnt += (x % 10 == 4 || x % 10 == 7);
            x /= 10;
        }
        if(cnt <= k) res++;
    }
    cout<<res;
    return 0;
}
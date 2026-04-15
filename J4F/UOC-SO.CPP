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

    ll n;
    cin>>n;
    int cnt = 0;
    for(int i = 1; 1LL * i * 1LL * i <= n; i++)
        if(n % i == 0){
            cnt += 2;
            if(1LL * i * i == n) cnt--;
        }
    cout<<cnt;
    return 0;
}
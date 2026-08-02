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

    int n;
    cin>>n;
    if(n == 0) return cout<<0, 0;

    int cnt = 0;
    while(n > 0){
        int x = n, maxx = 0;
        while(x > 0){
            maxx = max(maxx, x % 10);
            x /= 10;
        }
        n -= maxx;
        cnt++;
    }
    cout<<cnt;
    return 0;
}
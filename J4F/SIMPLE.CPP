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

    ll x = 19;
    int cnt = 0;
    while(cnt < n){
        int tmp = x, sum = 0;
        while(tmp > 0){
            sum += tmp % 10;
            tmp /= 10;
        }
        if(sum % 10 == 0) cnt++;
        if(cnt == n) return cout<<x, 0;
        x++;
    }
    return 0;
}
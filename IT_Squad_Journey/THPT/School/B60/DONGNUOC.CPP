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
#define taskname "DONGNUOC"

ll n;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll cnt = n / 5;
    if(n % 5 == 1 || n % 5 == 3 || n % 5 == 2)
        cnt++;
    else if(n % 5 == 4) cnt += 2; 
    cout<<cnt;
    return 0;
}
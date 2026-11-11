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

int tc = 1;

void sol(){
    int n, k;
    cin>>n>>k;
    if(n % 2){
        cout<<n / 2<<" "<<n / 2<<" 1";
        return;
    }

    if(n % 4) cout<<n / 2 - 1<<" "<<n / 2 - 1<<" 2";
    else cout<<n / 2<<" "<<n / 4<<" "<<n / 4;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}
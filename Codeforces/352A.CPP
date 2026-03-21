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

    int n, x;
    cin>>n;
    int cnt5 = 0, cnt0 = 0;
    for(int i = 0; i < n; i++){
        cin>>x;
        if(x == 5) cnt5++;
        else cnt0++;
    }

    if(!cnt0) return cout<<-1, 0;
    bool ok = 0;
    for(int i = 0; i < cnt5 - (cnt5 % 9); i++){
        cout<<5;
        ok = 1;
    }

    cout<<0;
    if(ok)
        for(int i = 1; i < cnt0; i++) cout<<0;
    return 0;
}
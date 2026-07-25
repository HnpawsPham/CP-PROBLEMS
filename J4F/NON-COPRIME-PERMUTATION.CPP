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
    int n;
    cin>>n;
    if(n < 5){
        cout<<-1;
        return;
    }

    if(n == 5){
        cout<<"2 4 5 1 3";
        return;
    }

    if(n == 6){
        cout<<"3 1 5 4 2 6";
        return;
    }
    
    for(int i = 1; i <= n; i+=2)
        if(i != 7 && i != 5) cout<<i<<" ";
    cout<<"7 5 4 ";

    for(int i = 2; i <= n; i+=2)
        if(i != 4) cout<<i<<" ";
    return;
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
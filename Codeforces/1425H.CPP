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
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    string res[4];
    
    if((a + b) % 2){
        res[0] = (a + d > 0 ? "Ya" : "Tidak");
        res[1] = (b + c > 0 ? "Ya" : "Tidak");
        res[2] = res[3] = "Tidak"; 
    }
    else{
        res[0] = res[1] = "Tidak";
        res[2] = (b + c > 0 ? "Ya" : "Tidak");
        res[3] = (a + d > 0 ? "Ya" : "Tidak");
    }

    for(int i= 0; i < 4; i++)
        cout<<res[i]<<" ";
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
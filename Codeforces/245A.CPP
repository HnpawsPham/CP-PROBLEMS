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
    int suma = 0, sumb = 0, senta = 0, sentb = 0;
    while(n--){
        int k, u, v;
        cin>>k>>u>>v;
        if(k == 1){
            suma += u + v;
            senta += u;
        }
        else{
            sumb += u + v;
            sentb += u;
        }
    }

    cout<<(senta >= suma / 2 ? "LIVE" : "DEAD")<<el;
    cout<<(sentb >= sumb / 2 ? "LIVE" : "DEAD");
    return 0;
}
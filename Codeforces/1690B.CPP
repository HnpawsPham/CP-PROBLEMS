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

string sol(){
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    int maxx = 0;
    for(int i = 0; i < n; i++){
        if(b[i] > a[i]) return "NO";
        maxx = max(maxx, a[i] - b[i]);
    }

    for(int i = 0; i < n; i++)
        if(!((b[i] == 0 && a[i] - maxx <= 0)
        || (a[i] - maxx == b[i]))) 
        return "NO";

    return "YES";
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
        cout<<sol()<<el;
    }
    return 0;
}
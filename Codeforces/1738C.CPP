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
    int a[n];
    int cnto = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i] & 1) cnto++;
    }

    if(cnto % 4 == 0 || cnto % 4 == 3) return "Alice";

    if(cnto % 4 == 1){
        if(n % 2) return "Bob";
        return "Alice";
    } 
    else return "Bob";
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
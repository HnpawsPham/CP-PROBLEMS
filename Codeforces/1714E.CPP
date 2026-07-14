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
    for(int i = 0; i < n; i++) cin>>a[i];

    bool has0 = 0;
    for(int& x : a){
        if((x % 10 == 0) || (x % 10 == 5)){
            x += (x % 10);
            has0 = 1;
        }
        else if(has0) return "NO";
    }
    
    if(has0){
        for(int i = 1; i < n; i++)
            if(a[i] != a[0]) return "NO";
        return "YES";
    }

    for(int& x : a){
        while((x % 10) != 2)
            x += (x % 10);
    }

    int mod = a[0] % 20;
    for(int i = 1; i < n; i++)
        if((a[i] % 20) != mod)  
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
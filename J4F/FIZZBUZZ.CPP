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
    string s;
    cin>>n>>s;
    int oo = 1e9;

    if(s == "fizzbuzz"){
        if(n == 1) cout<<"-1 -1";
        else cout<<1<<" "<<n;
    }
    else if(s == "fizz"){
        if(n == oo) cout<<1<<" "<<n - 1;
        else cout<<1<<" "<<oo;
    }
    else if(s == "buzz"){
        if(n == oo) cout<<3<<" "<<5;
        else if(n <= 2) cout<<"-1 -1";
        else cout<<n - 1<<" "<<n;
    }
    else{
        if(n == oo) cout<<"3 7";
        else if(n == 1) cout<<"2 3";
        else if(n == oo - 1) cout<<n - 1<<" "<<oo;
        else cout<<n + 1<<" "<<oo;
    }
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
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
    if(n == 1){
        cout<<"YES\n1";
        return;
    }
    if(n == 3){
        cout<<"NO";
        return;
    }
    
    cout<<"YES"<<el;
    if(n % 2){
        for(int i = 0; i < n / 2; i++) 
            cout<<n / 2 - 1<<" "<<-n / 2<<" ";
        cout<<n / 2 - 1;
    }
    else{
        for(int i = 0; i < n / 2; i++) 
            cout<<"1 -1 ";
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
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

    int a, b;
    cin>>b>>a;
    for(int i = 0; i < b - a; i++){
        for(int j = 0; j < b; j++)
            cout<<"* ";
        cout<<el;
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b - a; j++)
            cout<<"* ";
        cout<<el;
    }
    return 0;
}
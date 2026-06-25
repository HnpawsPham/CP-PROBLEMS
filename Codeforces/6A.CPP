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

int calc(int a, int b, int c){
    if((a + b > c) && (b + c > a) && (a + c > b)) return 1;
    if((a + b == c) || (a + c == b) || (c + b == a)) return 2;
    return 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(calc(a, b, c) == 1 || calc(b, c, d) == 1 || calc(a, b, d) == 1 || calc(a, c, d) == 1)
        cout<<"TRIANGLE";
    else if(calc(a, b, c) == 2 || calc(b, c, d) == 2 || calc(a, b, d) == 2 || calc(a, c, d) == 2) 
        cout<<"SEGMENT";
    else cout<<"IMPOSSIBLE";
    return 0;
}
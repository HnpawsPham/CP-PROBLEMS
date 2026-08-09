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

int a, b, c;

int cnt(int x){
    return (a == x) + (b == x) + (c == x);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c;

    if(cnt(1) >= 1 || cnt(2) >= 2 || cnt(3) == 3)
        return cout<<"YES", 0;
    
    if(cnt(2) && cnt(4) == 2)
        return cout<<"YES", 0;

    cout<<"NO";
    return 0;
}
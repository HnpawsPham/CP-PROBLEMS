#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll cnt = 1;
    int preva = 0, prevb = 0;
    cin>>n;

    while(n--){
        int a, b;
        cin>>a>>b;
        
        if(!(a == preva && b == prevb))
            cnt += max(0, min(a, b) - max(preva, prevb) + (preva != prevb));
            
        preva = a;
        prevb = b;
    }
    cout<<cnt;
    return 0;
}
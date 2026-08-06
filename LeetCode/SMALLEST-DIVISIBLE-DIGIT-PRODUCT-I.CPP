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

    int n, t;
    cin>>n>>t;
    for(int i = n; ;i++){
        int mul = 1, x = i;
        while(x > 0){
            mul *= (x % 10);
            x /= 10;
        }
        if(mul % t == 0) 
            return cout<<i, 0;
    }
    return 0;
}
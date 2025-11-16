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

int tc = 1;

string sol(){
    int a, b, c, t;
    cin>>a>>b>>c>>t;
    int sum = a + b + c;
    
    if(t % sum < a) return "Guiding Beat";
    else if(t % sum < a + b) return "Warning Beat";
    return "Resting Phase";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 2
// 3 5 2 6
// 4 4 4 11
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

int lcm(int a, int b){
    return (a * b) /__gcd(a, b);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin>>a>>b;
    if(b % a != 0) return cout<<-1, 0;

    int mul = a * b, minn = mul + 5;
    int resx = -1, resy = -1;
    for(int y = 1; y <= b; y++){
        if(mul % y == 0){
            int x = mul / y;
            if(__gcd(x, y) == a && minn > x + y){
                minn = x + y;
                resx = x;
                resy = y;
            }
        }
    }
    if(resx == -1) return cout<<-1, 0;

    if(resx > resy) swap(resx, resy);
    cout<<minn<<el<<resx<<" "<<resy;
    return 0;
}
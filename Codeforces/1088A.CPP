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

    int x;
    cin>>x;
    
    for(int a = 1; a <= x; a++)
        for(int b = 1; b <= a; b++)
            if((b % a == 0) && a * b > x && a / b < x)
                return cout<<a<<" "<<b, 0;
    cout<<-1;
    return 0;
}
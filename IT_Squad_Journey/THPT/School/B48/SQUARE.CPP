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
#define taskname "SQUARE"

string s;

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return half * half * a;
    return half * half;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int sum = 0;
    for(const char&x : s)
        sum += ppow(int(x - '0'), 2);
    cout<<sum;
    return 0;
}
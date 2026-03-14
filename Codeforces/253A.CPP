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
#define taskname ""

int main(){
    #ifdef taskname
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    char boy = 'B', girl = 'G';
    if(n < m){
        swap(n, m);
        swap(boy, girl);
    }

    while(n > 0 && m > 0){
        cout<<boy<<girl;
        m--;
        n--;
    }

    if(n > 0)
        while(n--) cout<<boy;
    return 0;
}
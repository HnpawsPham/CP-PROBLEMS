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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin>>a>>b;
    if(a < b) swap(a, b);
    int cnt = 0;
    while(a && b){
        a -= b;
        cnt++;
        if(a < b) swap(a, b);
    }
    cout<<cnt;
    return 0;
}
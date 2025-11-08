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

int sol(int n){
    if(n == 0) return 0;

    int k = 1, tmp = 1;
    while(tmp * 2 <= n){
        tmp *= 2;
        k++;
    }// bit 1 cao nhat
    return (1 << (k + 1)) - 1 - sol(n ^ tmp);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
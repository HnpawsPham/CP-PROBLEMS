#include <bits/stdc++.h>
using namespace std;
using ll = long long
using db = double
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);

    if(b & 1) return half * half * a;
    return half * half;
}

bool sol(){
    if(n <= 0) return 0;

    for(int i = 0; i <= 31; i++)
        if(ppow(2, i) == n) return 1;

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    cout<<sol();
    return 0;
}
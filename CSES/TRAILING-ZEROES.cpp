#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);

    if(b & 1) return half * half * a;
    return half * half;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int cnt = 0;
    for(int i = 1; ; i++){
        int x = ppow(5, i);
        if(x > n) break;

        cnt += n / x;
    }
    cout<<cnt;
    return 0;
}
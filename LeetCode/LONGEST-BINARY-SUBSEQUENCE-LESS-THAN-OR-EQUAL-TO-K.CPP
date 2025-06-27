#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

string s;
int k;

double ppow(int a, int b){
    if(b == 0) return 1;
    double half = ppow(a, b / 2);

    if(b & 1) return (double)half * half * a;
    return (double)half * half;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>k;
    int n = s.length();

    int res = 0;
    ll sum = 0;

    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '0'){
            res++;
            continue;
        }

        int d = n - i - 1;
        if(d >= 63) continue; // prevent overflow

        ll val = (s[i] - '0') * (1LL << d);

        if(sum + val <= k){
            sum += val;
            res++;
        }
    }
    cout<<res;
    return 0;
}
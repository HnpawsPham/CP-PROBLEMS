#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return half * half * a;
    return half * half;
}

int fact(int n){
    if(n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}

int C(int n, int k){
    if(k < 0 || k > n) return 0;
    return fact(n) / (fact(k) * fact(n - k)); 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin>>s>>t;

    int sum1 = 0, sum2 = 0;
    for(const char& x : s){
        if(x == '+') sum1++;
        else sum1--;
    }

    int miss = 0;
    for(const char& x : t){
        if(x == '+') sum2++;
        else if(x == '-') sum2--;
        else miss++;
    }

    int need = (sum1 - sum2 + miss) / 2;
    
    cout<<fixed<<setprecision(10);
    cout<<(db) C(miss, need) / ppow(2, miss);
    return 0;
}
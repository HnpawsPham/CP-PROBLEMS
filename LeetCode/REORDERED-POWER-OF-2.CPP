#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

bool sol1(){
    string s = to_string(n);
    sort(s.begin(), s.end());

    do{
        if(s[0] == '0') continue;

        int x = stoi(s);
        if(x > 0 && !(x & (x - 1))) return 1;
    }  while(next_permutation(s.begin(), s.end()));

    return 0;
}

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);

    if(b & 1) return half * half * a;
    return half * half;
}

bool sol2(){
    vi cnt(10, 0);
    int tmp = n;
    
    while(tmp > 0){
        cnt[tmp % 10]++;
        tmp /= 10;
    }

    vector<vi> p(31, vi(10, 0));
    for(int i = 0; i < 31; i++){
        int x = ppow(2, i);
        while(x > 0){
            p[i][x % 10]++;
            x /= 10;
        }
    }

    for(vi v : p)
        if(v == cnt) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<sol2();
    return 0;
}
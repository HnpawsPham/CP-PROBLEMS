#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int calc(string s){
    int x = stoi(s), tmp, sum;

    while(x > 9){
        tmp = x;
        sum = 0;
        while(tmp > 0){
            sum += tmp % 10;
            tmp /= 10;
        }
        x = sum;
    }
    return x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();
    int cnt = 0, l, r;

    for(int i = 0; i < n - 1; i++){
        if(s[i + 1] == '0') continue;
        l = calc(s.substr(0, i + 1));
        r = calc(s.substr(i + 1, n - i));
        if(l < r) cnt++;
    }
    cout<<cnt;
    return 0;
}
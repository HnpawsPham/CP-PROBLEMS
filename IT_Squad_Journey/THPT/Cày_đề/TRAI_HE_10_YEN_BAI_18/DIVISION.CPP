#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t, x, l;
string s;

int to_int(char x){
    return int(x - '0');
}

int main(){
    freopen("DIVISION.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>x>>l>>s;
        int n = s.length();
        int d = 1, sum = to_int(s[l - 1]), cnt = 0;

        for(int i = l - 2; i >= 0; i--){
            d = (d * 10) % x;
            int cur = to_int(s[i]) * d % x;
            sum = (sum + cur) % x;
        }
        if(sum == 0) cnt++;

        for(int i = l; i < n; i++){
            int keep = sum - to_int(s[i - l]) * d;
            sum = (keep * 10 + to_int(s[i])) % x;
            if (sum == 0 && s[i - l + 1] != '0') cnt++;
        }
        cout<<cnt<<el;;
    }
    return 0;
}
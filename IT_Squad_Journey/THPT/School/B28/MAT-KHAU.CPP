#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"

string str, cur;

int main(){
    freopen("MAT-KHAU.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    ll sum = 0;
    int n = str.length();
    for(int i = 0; i < n; i++){
        if('0' <= str[i] && str[i] <= '9') cur += str[i];
        else if(!cur.empty()){
            sum += stoull(cur);
            cur = "";
        }
    }
    if(!cur.empty()) sum += stoull(cur);
    cout<<sum;
    return 0;
}
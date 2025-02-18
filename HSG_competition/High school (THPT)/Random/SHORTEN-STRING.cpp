#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>str;

    int n = str.length();
    int cnt = 0;
    char prev = str[0];
    string res = "";

    for(int i = 1; i < n; i++){
        cnt++;
        if(str[i] != prev){
            res +=to_string(cnt) + prev;
            cnt = 0;
            prev = str[i];
        }
    }
    res += to_string(cnt + 1) + prev;

    cout<<res;

    return 0;
}
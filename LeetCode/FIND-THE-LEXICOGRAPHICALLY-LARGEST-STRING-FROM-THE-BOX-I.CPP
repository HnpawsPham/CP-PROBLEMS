#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;
int k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>k;
    int n = s.length();

    // SUB 1
    // string res = "";
    // int maxlen = n - k + 1;

    // for(int i = 0; i < n; i++){
    //     int len = min(n - i, maxlen);
    //     string ss = s.substr(i, len);

    //     if(res < ss) res = ss;
    // }
    // cout<<res;

    // SUB2
    int i = 0, j = 1, k = 0;
    while(j + k < n){
        if(s[i + k] == s[j + k]) k++;

        else if(s[i + k] < s[j + k]){
            i = max(i + k + 1, j);
            j = i + 1;
            k = 0;
        }
        else{
            j = j + k + 1;
            k = 0;
        }
    }

    cout<<s.substr(i, maxlen);

    return 0;
}
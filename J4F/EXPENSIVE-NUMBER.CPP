#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int n = s.length();
        int cnt = 0;
        bool ok = 0;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] != '0') ok = 1;
            else if(ok) cnt++;
        }
        cout<<n - cnt - 1<<el;
    }

    return 0;
}
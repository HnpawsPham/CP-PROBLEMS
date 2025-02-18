#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int t, n;
string str;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>t;
    while(t--){
        cin>>n>>str;
        if(n % 2 == 0) {
            cout<<"No solution"<<el; continue;
        }

        int cnt = 0;
        int len = n / 2;
        string s = "";

        for(int i = 0; i < n - len; ++i){
            bool t1 = (str[i] == str[i + len]);
            bool t2 = (str[i] == str[i + len + 1]);

            if(t1 || t2){
                cnt = cnt + t1 + t2;
                s = s + str[i];
            }
        }
        // cout<<s<<" "<<cnt<<el;
        if(cnt == len) cout<<s<<el;
        else cout<<"Multiple Solutions"<<el;
    }

    return 0;
}
// 3
// 9
// ABUCDABCD
// 10
// HELLOWORLD
// 9
// GKGKGKGKG
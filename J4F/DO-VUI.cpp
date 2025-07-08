#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int t, n;
string s;

string sol(){
    if(n % 2 == 0) return "No Solution";

    int d = 0;
    string res = "No Solution", s1 = "", s2 = "";

    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n / 2 + i + d] && !d){
            d++;
            i--;
        } 
        else if(s[i] != s[n / 2 + i + d] && d){
            s1 = "";
            break;
        }
        else s1 += s[i];
    }

    if(!s1.empty()) res = s1;

    d = 0;
    for(int i = 0; i < n / 2; i++){
        if(s[i + d] != s[n / 2 + i + 1] && !d){
            d++;
            i--;
        } 
        else if(s[i + d] != s[n / 2 + i + 1] && d){
            s2 = "";
            break;
        }
        else s2 += s[i + d];
    }

    if (s2 != ""){
        if (res != "No Solution" && res != s2)
            res = "Multiple Solutions";
        else res = s2;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>s;
    cout<<sol();

    return 0;
}
// 3
// 9
// ABUCDABCD
// 10
// HELLOWORLD
// 9
// GKGKGKGKG
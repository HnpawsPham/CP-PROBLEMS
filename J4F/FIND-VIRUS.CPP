#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s, t = "virus";

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length(), m = t.length();

    int lps[m] = {0};
    int i = 1, j = 0;
    
    while(i < m){
        if(t[i] == t[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j == 0) {
                lps[i] = 0;
                i++;
            }
            else j = lps[j - 1];
        }
    }

    i = 0; j = 0;
    int cnt = 0;

    while(n - i >= m - j){
        if(s[i] == t[j]){
            i++;
            j++;
        }
        
        if(j == m){
            cnt++;
            j = lps[j - 1];
        }
        else if(i < n && s[i] != t[j]){
            if(j == 0) i++;
            else j = lps[j - 1];
        }
    }
    cout<<cnt;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
#define el "\n"

string s, se, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>s>>se;
    int n = s.length(), q = se.length();

    for(int k = min(q, n); k > 0; k--){
        t = se.substr(0, k);
        int m = t.length();

        if(n < m) continue;

        int lps[m] = {0};
        int i = 1, j = 0;

        while(i < m){
            if(t[i] == t[j]){
                j++;
                lps[i] = j;
                i++;
            }
            else{
                if(j == 0){
                    lps[i] = 0;
                    i++;
                }
                else j = lps[j - 1];
            }
        }

        i = 0; j = 0;
        while(n - i >= m - j){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            if(j == m && i == n)
                return cout<<n + q - m, 0;

            else if(i < n && s[i] != t[j]){
                if(j == 0) i++;
                else j = lps[j - 1];
            }
        }
    }
    cout<<n + q;
    return 0;
}
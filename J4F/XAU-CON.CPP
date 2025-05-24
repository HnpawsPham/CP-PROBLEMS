#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>t;
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
            if(j > 0)
                j = lps[j - 1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    i = 0; j = 0;
    vector<int> res;

    while(n - i >= m - j){
        if(s[i] == t[j]){
            i++;
            j++;
        }

        if(j == m){
            res.push_back(i - m + 1);
            j = lps[j - 1];
        }
        else if(i < n && s[i] != t[j]){
            if(j == 0) i++;
            else j = lps[j - 1];
        }
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}
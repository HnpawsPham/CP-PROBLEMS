#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

string sol(string s){
    int n = s.length();
    for (int i = 0; i < n; i++) {
        string s1 = {s[i]};
        if (stoi(s1) % 8 == 0) 
            return "YES\n" + s1;

        for (int j = i + 1; j < n; j++) {
            string s2 = {s[i], s[j]};
            if (stoi(s2) % 8 == 0) 
                return "YES\n" + s2;
      
            for (int k = j + 1; k < n; k++) {
                string s3 = {s[i], s[j], s[k]};
                if (stoi(s3) % 8 == 0) 
                    return "YES\n" + s3;
            }
        }
    }
    return "NO";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    cout<<sol(s);
    return 0;
}
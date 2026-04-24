#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    cin.ignore();

    while(n--){
        string str;
        getline(cin, str);

        stringstream ss(str);
        string s;
        bool first = 1;

        while(ss >> s){
            if(!first) cout<<" ";
            first = 0;

            int m = s.length();
            cout<<(char)toupper(s[0]);
            for(int i = 1; i < m; i++) cout<<(char)tolower(s[i]);
        }
        cout<<el;
    }
    return 0;
}
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

    string s;
    cin>>s;

    int n = s.length();
    int open = 0, res = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') open++;
        else{
            if(i + 1 < n && s[i + 1] == ')')
                i++;
            else res++;

            if(open > 0) open--;
            else res++; 
        }
    }
    cout<<res + open * 2;
    return 0;
}
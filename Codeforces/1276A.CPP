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

int tc = 1;

void sol(){
    string s;
    cin>>s;
    int n = s.length();

    vi res;
    for(int i = 0; i < n;){
        // for(const string& x : {"twone", "one", "two"}){
        //     int pos = s.find(x);
        //     if(pos == -1) continue;

        //     int mid = pos + (x.size() + 1) / 2;
        //     s[mid - 1] = '-';
        //     res.push_back(mid);
            
        //     i += x.size() - 1;
        //     break;
        // }
        if(i + 4 < n && s.substr(i, 5) == "twone"){
            res.push_back(i + 3);
            i += 5;
        }
        else if(i + 2 < n && s.substr(i, 3) == "one"){
            res.push_back(i + 2);
            i += 3;
        }
        else if(i + 2 < n && s.substr(i, 3) == "two"){
            res.push_back(i + 2);
            i += 3;
        }
        else i++;
    }

    cout<<res.size()<<el;
    for(int x : res) cout<<x<<" ";
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}
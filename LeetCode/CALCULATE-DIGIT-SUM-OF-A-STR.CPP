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
    int k;
    cin>>s>>k;
    
    while(s.size() > k){
        string tmp = "";
        int n = s.length(), cnt = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (s[i] - '0');
            cnt++;
            if(cnt == k){
                tmp += to_string(sum);
                sum = cnt = 0;
            }
        }
        if(cnt) tmp += to_string(sum);
        s = tmp;
    }
    cout<<s;
    return 0;
}
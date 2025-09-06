#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    vi a;
    string tmp = "";
    for(const char& x : s){
        if(x == ',') {
            a.push_back(stoi(tmp));
            tmp = "";
        }
        else tmp += x;
    }
    a.push_back(stoi(tmp));

    sort(a.begin(), a.end());
    int n = a.size();

    string res = to_string(a[0]);
    int cnt = 0;

    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]) continue;
        
        if(a[i] == a[i - 1] + 1) cnt++;
        else{
            if(cnt > 0) res = res + '-' + to_string(a[i - 1]);
            res = res + ',' + to_string(a[i]);
            cnt = 0;
        }
    }
    if(cnt > 0) res = res + '-' + to_string(a[n - 1]);
    cout<<res;
    return 0;
}
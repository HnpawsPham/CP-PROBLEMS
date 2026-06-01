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
        freopen(taskname".OUT", "sum", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<string> res, row;
    int sum = 0;

    for(int i = 0; i < n;){
        if(sum + a[i].size() + row.size() <= m){
            row.push_back(a[i]);
            sum += a[i].size();
            i++;
        }
        else{
            int sz = row.size() - 1;
            int space = (m - sum) / max(1, sz);
            int left = (sz > 0 ? (m - sum) % sz : 0);
            
            string blank = "";
            while(space--) blank.push_back(' ');

            for(int i = 0; i < sz; i++)
                row[i] = row[i] + blank;

            for(int i = 0; left; i++){
                row[i].push_back(' ');
                left--;
            }

            string tmp = "";
            for(const string& x : row)
                for(const char& c : x)
                    tmp.push_back(c);

            res.push_back(tmp);
            row.clear();
            sum = 0;
        }
    }

    string tmp = "";
    int sz = row.size();
    for(int i = 0; i < sz - 1; i++){
        row[i].push_back(' ');
        tmp = tmp + row[i];
    }
    tmp += row[sz - 1];

    while(tmp.size() < m)
        tmp.push_back(' ');

    res.push_back(tmp);

    for(const string& s : res)
        cout<<s<<el;
    return 0;
}

// 7 16
// This is an example of text justification
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define vi vector<int>
#define pii pair<int, char>
#define fi first
#define se second

int n;
const int maxn = 2e5 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    getline(cin, line); 

    stringstream ss(line);
    vector<string> a;
    string tmp;

    while (ss >> tmp) a.push_back(tmp);

    char f0 = a[0][0];
    vi id(26, 11);
    id[f0 - 'A'] = 0;

    int sz = a.size();
    for (int i = 1; i + 2 < sz; i += 3) {
        int u = a[i][0] - 'A';
        int v = a[i + 1][0] -'A';
        int d = stoi(a[i + 2]);

        if (d <= 2) {
            if(id[u] > id[v]) id[u] = id[v] + 1;
            else if(id[u] < id[v]) id[v] = id[u] + 1;
        }
    }

    vector<pii> res;
    for(int i = 0; i < 26; i++)
        if(id[i] != 11) 
            res.push_back({id[i], char(i + 'A')});

    sort(res.begin(), res.end());
    for(auto [_, x] : res) cout<<x<<" ";
    return 0;
}

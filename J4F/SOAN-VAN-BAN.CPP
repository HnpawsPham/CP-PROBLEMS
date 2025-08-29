#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>

bool check(const string &s, const string &t) {
    int j = 0;
    int n = s.length(), m = t.length(); 

    for (int i = 0; i < n; i++) {
        if (j < m && s[i] == t[j]) j++;
        else if (s[i] != s[i - 1]) return 0;
    }
    return j == m;
}

// bool check2(const string &s, const string &t){
//     vi cnts(26, 0), cntt(26, 0);
//     for(char x : s) cnts[x - 'a']++;
//     for(char x : t) cntt[x - 'a']++;

//     for(int i = 0; i < 26; i++)
//         if((cnts[i] > 0 && cntt[i] == 0)
//         || (cnts[i] < cntt[i])) return 0;
//     return 1;
// }

int main() {
    // freopen("BAI2.INP", "r", stdin);
    // freopen("BAI2.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    getline(cin, s);
    getline(cin, t);
    s = '/' + s;
    t = '/' + t;

    stringstream ss(s), st(t);
    string w1, w2;
    int cnt = 0;
    while (ss >> w1 && st >> w2) 
        if (check(w1, w2)) cnt++;
    
    cout << cnt;
    return 0;
}

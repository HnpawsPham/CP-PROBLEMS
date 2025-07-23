#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int n, m;
string s;
int res = 55;
vi used, fs, sum; 
vector<vi> mp;

bool ok(){
    for(int i = 0; i < 26; i++)
        if(fs[i] && sum[i] < fs[i]) return 0;
    return 1;
}

void sol(int cnt) {
    if (cnt >= res) return;
    if (ok()) {
        res = cnt;
        return;
    }

    // find char that appears the least
    int ch = -1, maxx = 0;
    for(int i = 0; i < 26; i++){
        if(fs[i] - sum[i] > maxx){
            maxx = fs[i] - sum[i];
            ch = i;
        }
    }
    if(ch == -1) return;

    for (int j = 0; j < m; j++) {
        if(!mp[j][ch]) continue;

        for(int x = 0; x < 26; x++)
            sum[x] += mp[j][x];

        used[j]++;
        sol(cnt + 1);
        used[j]--;

        for(int x = 0; x < 26; x++)
            sum[x] -= mp[j][x];
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m;
    mp.resize(m, vi(26, 0));
    used.assign(m, 0);
    fs.assign(26, 0);
    sum.assign(26, 0);

    vector<string> a(m);
    for(int i = 0; i < m; i++) cin>>a[i];

    cin>>s;
    n = s.length();

    // calc chars freq
    for(const char& x : s)
        fs[x - 'a']++;

    for(int i = 0; i < m; i++)
        for(const char&x : a[i])
            mp[i][x - 'a']++;

    // check impossible
    for(int i = 0; i < 26; i++){
        if(!fs[i]) continue;

        int cnt = 0;
        for(int j = 0; j < m; j++)
            cnt += mp[j][i];

        if(cnt == 0) return cout<<-1, 0;
    }

    sol(0);

    cout<<res;
    return 0;
}

// 3
// with example science
// thehat

// 2
// notice possible
// basicbasic

// 3
// a b c
// abcabcabcabc 
#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;
int n, l, res;
unordered_map<char, int> mp;

bool is_vow(char x) {
    return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

int cnt_substr(int num){
    mp.clear();
    l = 0, res = 0;

    for (int r = 0; r < n; r++) {
        if (!is_vow(str[r])){
            mp.clear(); 
            l = r + 1; 
            continue;
        }
        mp[str[r]]++;

        while (mp.size() > num) 
            if(--mp[str[l]]) mp.erase(str[l]);
        res += (r - l + 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    n = str.length();
    cout<<cnt_substr(5) - cnt_substr(4);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define el "\n"

bool is_vow(char x) {
    return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int n = str.length();
    
    unordered_map<char, int> mp;
    int l = 0, res = 0;

    for (int r = 0; r < n; r++) {
        if (is_vow(str[r])) 
            mp[str[r]]++;
        else {  
            mp.clear(); 
            l = r + 1; 
        }

        while(mp.size() == 5) {
            mp[str[l]]--;
            if (mp[str[l]] == 0) break;
            res++;
            l++; 
        }
    }
 
    cout << res;
    return 0;
}

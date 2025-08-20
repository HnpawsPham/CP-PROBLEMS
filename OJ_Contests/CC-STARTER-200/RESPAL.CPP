#include <bits/stdc++.h>
using namespace std;

string sol(){
    int n; cin >> n;
    string pattern = "abc";
    string s = "";
    for(int i = 0; i < n; i++){
        s += pattern[i % 3];
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        cout << sol() << '\n';
    }
    return 0;
}

#include <iostream>
using namespace std;

#define el "\n"

int n;
const int maxn = 100005;
int p[maxn] = {};  
char s[maxn]; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    s[0] = '|';
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        s[2 * i + 1] = c;
        s[2 * i + 2] = '|';
    }

    n = 2 * n + 1;
    
    int r = 0, c = 0, res = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) 
            p[i] = min(p[2 * c - i], r - i);

        while(i + p[i] < n && s[i + p[i]] == s[i - p[i]]) 
            p[i]++;

        if(i + p[i] > r) {
            r = i + p[i];
            c = i;
        }
        res = max(res, p[i] - 1);
    }

    cout << res;
    return 0;
}

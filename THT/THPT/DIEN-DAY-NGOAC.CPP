#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int q;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> s;
        
        int maxx = 0, minn = 0;
        bool ok = 1;

        for(char x : s){
            if(x == '('){
                maxx++;
                minn++;
            }
            else if(x == ')'){
                maxx--;
                minn--;
            }
            else{
                maxx++;
                minn--;
            }

            if(maxx < 0){
                ok = 0;
                break;
            }
            else if(minn < 0){
                if(minn % 2 == 0) minn = 0;
                else minn = 1;
            }
        }
        if(ok && minn <= 0 && maxx >= 0) cout<<"YES"<<el;
        else cout<<"NO"<<el;
    }
    return 0;
}
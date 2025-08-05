#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        int cnt[26] = {0};
        for(char x : s)
            cnt[x - 'a']++;

        int maxx = 0, minn = n + 1;
        char minch, maxch;
        for(int i = 0; i < 26; i++){
            if(cnt[i] == 0) continue;

            if(cnt[i] >= maxx) {
                maxx = cnt[i];
                maxch = char(i + 'a');
            }
            if(cnt[i] < minn){
                minn = cnt[i];
                minch = char(i + 'a');
            }
        }
        
        for(char& x : s)
            if(x == minch) {
                x = maxch;
                break;
            }
        cout<<s<<el;
    }

    return 0;
}
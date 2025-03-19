#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;

bool check(int n){
    int low = 0, up = 0, num = 0;

   for(int r = 0; r < n;r++){
        low += ('a' <= str[r] && str[r] <= 'z');
        up += ('A' <= str[r] && str[r] <= 'Z');
        num += ('0' <= str[r] && str[r] <= '9');
   }
   return(low && up && num);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    int n = str.length();

    if(!check(n)) {
        cout<<0; return 0;
    }

    int l = 0, r = 0, minn = n, len = n;
    int rlow = -1, rup = -1, rnum = -1;

    while(l < n - 3 && r < n){
        if('a' <= str[r] && str[r] <= 'z' && rlow == -1) rlow = r;
        if('A' <= str[r] && str[r] <= 'Z' && rup == -1) rup = r;
        if('0' <= str[r] && str[r] <= '9' && rnum == -1) rnum = r;

        r++;

        if(rlow >= 0 && rup >= 0 && rnum >= 0) {
            minn = max(rlow, max(rup, rnum));
            len = min(minn - l + 1, len);
            rlow = -1, rup = -1, rnum = -1;
            l++;
            r = l;
        }
    }

    cout<<(n - len) * (n - len - 1);

    return 0;
}
// abc3456789PQ
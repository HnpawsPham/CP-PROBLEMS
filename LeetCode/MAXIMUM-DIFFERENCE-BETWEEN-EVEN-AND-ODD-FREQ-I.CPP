#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int cnt[26] = {0};

    for(const char& x : s)
        cnt[x - 'a']++;
    
    int maxx = 0, minn = s.length();
    for(int x : cnt){
        if(x % 2 && x > maxx) 
            maxx = x;
        
        if(x > 0 && x % 2 == 0 && x < minn)
            minn = x;
    }
    cout<<maxx - minn;
    return 0;   
}
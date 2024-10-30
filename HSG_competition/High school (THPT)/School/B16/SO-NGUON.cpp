#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str, sv;
int n;

string minus_str(int val){
    string res = "";
    int len = str.length();
    int t = 0;

    for(int i = len - 1; i >= 0; i--){
        int c = int(str[i] - '0');
        int m = val % 10 + t; 
        val /= 10;

        if(c < m){
            c += 10;
            t = 1;
        }    
        else t = 0;

        res = to_string(c - m) + res;
    }

    int cnt = 0;
    for(int i = 0; i<len; i++){
        if(res[i] != '0') break;
        cnt++;
    }
    res = res.substr(cnt);

    return res;
}

string get_sum(string s){
    int res = 0;
    int len = s.length();

    for(int i = 0; i < len; i++){
        res += int(s[i] - '0');
    }

    int t = 0;
    string sum = "";

    for(int i = len - 1; i >= 0; i--){
        int c = int(s[i] - '0');
        int m = res % 10 + t;
        res /= 10;

        if(c + m > 9){  
            t = 1;
            m -= 10;
        } else t = 0;

        sum = to_string(c + m) + sum;
    }
    return sum;
}

int main(){
    freopen(".\\txt\\SO-NGUON.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    sv = str;
    n = str.length();

    if(n < 2){
        cout<<-1<<el;
        return 0;
    }

    string res = "-1";
    
    int limit = 905;  
    if(n < 4) limit = min(stoi(str), limit);

    for(int i = 1; i <= limit; i++){
        string ss = minus_str(i);
        string sum = get_sum(ss);
        if(sum == sv) res = ss; 
    }
    cout<<res<<el;
    
    return 0;
}
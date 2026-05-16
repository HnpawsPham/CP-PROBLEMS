#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int tc = 1;

string sol(){
    int d;
    string s;
    cin>>d>>s;

    if((d >= 21 && s == "Mar") || (d <= 20 && s == "Apr"))
        return "Aries";
    else if((d >= 21 && s == "Apr") || (d <= 20 && s == "May"))
        return "Taurus";
    else if((d >= 21 && s == "May") || (d <= 21 && s == "Jun"))
        return "Gemini";
    else if((d >= 22 && s == "Jun") || (d <= 22 && s == "Jul"))
        return "Cancer";
    else if((d >= 23 && s == "Jul") || (d <= 22 && s == "Aug"))
        return "Leo";
    else if((d >= 23 && s == "Aug") || (d <= 21 && s == "Sep"))
        return "Virgo";
    else if((d >= 22 && s == "Sep") || (d <= 22 && s == "Oct"))
        return "Libra";
    else if((d >= 23 && s == "Oct") || (d <= 22 && s == "Nov"))
        return "Scorpio";
    else if((d >= 23 && s == "Nov") || (d <= 21 && s == "Dec"))
        return "Sagittarius";
    else if((d >= 22 && s == "Dec") || (d <= 20 && s == "Jan"))
        return "Capricorn";
    else if((d >= 21 && s == "Jan") || (d <= 19 && s == "Feb"))
        return "Aquarius";
    return "Pisces";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}
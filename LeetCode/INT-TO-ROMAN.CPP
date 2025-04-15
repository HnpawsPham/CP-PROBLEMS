#include <bits/stdc++.h>
using namespace std;
#define pis pair<int, string>
#define fi first
#define se second

int num;
vector<pair<int, string>> roman = {
    {1000, "M"}, 
    {900, "CM"}, 
    {500, "D"}, 
    {400, "CD"}, 
    {100, "C"},
    {90, "XC"},  
    {50, "L"},   
    {40, "XL"}, 
    {10, "X"},   
    {9, "IX"},
    {5, "V"},    
    {4, "IV"},  
    {1, "I"}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>num;
    string res = "";

    for(const pis x : roman){
        if(num == 0) break;

        while(num >= x.fi){
            res += x.se;
            num -= x.fi;
        }
    }
    cout<<res;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();

    if(n < 3) return cout<<0, 0;

    unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u'};
    bool vowel = 0, consonant = 0;

    for(char x : s){
        if(!isalnum(x)) return cout<<0, 0;

        if(vow.count(tolower(x))) vowel = 1;
        else if(!isdigit(x)) consonant = 1;
    }
    cout<<(vowel && consonant);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define el "\n"

class Book{
    public:
        string title, author;
        int year;
};

int main(){
    Book fav1, fav2;

    fav1.title = "Matilda";
    fav1.author = "Roald Dahl";
    fav1.year = 1988;

    fav2.title = "The Giving Tree";
    fav2.author = "Shel Silverstein";
    fav2.year = 1964;

    cout << fav1.title << ", " << fav1.author << ", " << fav1.year << "\n";
    cout << fav2.title << ", " << fav2.author << ", " << fav2.year;
    return 0;
}
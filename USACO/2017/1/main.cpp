#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

struct Cow {
    string name;
    int num;
};

string names[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

// Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta
Cow cows[7] = {
    {"Bessie", 0},
    {"Elsie", 0},
    {"Daisy", 0},
    {"Gertie", 0},
    {"Annabelle", 0},
    {"Maggie", 0},
    {"Henrietta", 0}
};

bool cmp (Cow a, Cow b) {
    return a.num < b.num;
}
int n, a;
string s;
int main() {
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> s >> a;
        for (int j = 0; j < 7; j++) {
            if (s == names[j]) {
                cows[j].num += a;
            }
        }
    }
    sort (cows, cows + 7, cmp);
    int index = 0;
    while (index < 7 && cows[index].num == cows[0].num) {
        index++;
    }
    if (index == 7 || index < 6 && cows[index].num == cows[index + 1].num) {
        fout << "Tie" << endl;
        return 0;
    } else {
        fout << cows[index].name << endl;
    }
}
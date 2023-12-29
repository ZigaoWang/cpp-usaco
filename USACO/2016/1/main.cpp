#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int X, Y, M;
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    fin >> X >> Y >> M;

    int maxMilk = 0;
    for (int x = 0; x * X <= M; ++x) {
        for (int y = 0; x * X + y * Y <= M; ++y) {
            maxMilk = max(maxMilk, x * X + y * Y);
        }
    }

    fout << maxMilk << endl;
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");
    int N;
    fin >> N;
    int cow[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch;
            fin >> ch;
            cow[i][j] = ch - '0';
        }
    }

    int flips = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (cow[i][j] == 1) {
                flips++;
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++) {
                        cow[x][y] = 1 - cow[x][y];
                    }
                }
            }
        }
    }
    fout << flips << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int M, N, K;
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    fin >> M >> N >> K;

    string signal[M];
    for (int i = 0; i < M; i++) {
        fin >> signal[i];
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            for (int l = 0; l < N; l++) {
                for (int m = 0; m < K; m++) {
                    fout << signal[i][l];
                }
            }
            fout << endl;
        }
    }

    return 0;
}

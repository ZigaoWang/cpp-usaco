#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int N;
    fin >> N;

    int bucketChanges[1010] = {0};

    int si, ti, bi;
    for (int i = 0; i < N; i++) {
        fin >> si >> ti >> bi;
        bucketChanges[si] += bi;
        bucketChanges[ti] -= bi;
    }

    int maxBuckets = 0;
    int currentBuckets = 0;
    for (int i = 0; i < 1001; i++) {
        currentBuckets += bucketChanges[i];
        if (currentBuckets > maxBuckets) {
            maxBuckets = currentBuckets;
        }
    }

    fout << maxBuckets << endl;
    return 0;
}
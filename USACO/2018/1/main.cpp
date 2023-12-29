#include <iostream>
#include <fstream>
using namespace std;

int bucketCap[4], bucketMilk[4];
int pourMilk (int from, int to) {
    int milkPoured;
    if (bucketMilk[from] + bucketMilk[to] > bucketCap[to]) {
        milkPoured = bucketCap[to] - bucketMilk[to];
        bucketMilk[from] -= milkPoured;
        bucketMilk[to] = bucketCap[to];
    } else {
        milkPoured = bucketMilk[from];
        bucketMilk[to] += bucketMilk[from];
        bucketMilk[from] = 0;
    }
    return milkPoured;
}

int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    for (int i = 1; i <= 3; i++) {
        fin >> bucketCap[i] >> bucketMilk[i];
    }
    for (int i = 1; i <= 33; i++) {
        pourMilk(1, 2);
        pourMilk(2, 3);
        pourMilk(3, 1);
    }
    pourMilk(1, 2);
    for (int i = 1; i <= 3; i++) {
        fout << bucketMilk[i] << endl;
    }
    return 0;
}

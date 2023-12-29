#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int N;
    fin >> N;

    // Assuming the maximum time can be 1000 based on problem constraints
    int bucketChanges[1001] = {};  // Initialize changes in bucket usage to 0

    int si, ti, bi;
    for (int i = 0; i < N; i++) {
        fin >> si >> ti >> bi;
        bucketChanges[si] += bi; // Increase buckets at start time
        bucketChanges[ti] -= bi; // Decrease buckets at end time
    }

    // Determine the maximum number of buckets required at any time
    int maxBuckets = 0;
    int currentBuckets = 0;
    for (int i = 0; i < 1001; i++) {
        currentBuckets += bucketChanges[i]; // Update current bucket usage
        if (currentBuckets > maxBuckets) {
            maxBuckets = currentBuckets;
        }
    }

    fout << maxBuckets << endl;
    return 0;
}
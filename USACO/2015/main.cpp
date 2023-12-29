#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 100;

int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int N, M;
    fin >> N >> M;

    int roadLengths[MAXN], roadSpeeds[MAXN], bessieLengths[MAXN], bessieSpeeds[MAXN];

    // Input for road segments
    for (int i = 0; i < N; ++i) {
        fin >> roadLengths[i] >> roadSpeeds[i];
    }

    // Input for Bessie's journey
    for (int i = 0; i < M; ++i) {
        fin >> bessieLengths[i] >> bessieSpeeds[i];
    }

    int maxOverSpeed = 0;
    int roadIndex = 0, bessieIndex = 0;
    int roadPosition = 0, bessiePosition = 0;

    while (roadIndex < N && bessieIndex < M) {
        int minDistance = min(roadLengths[roadIndex] - roadPosition, bessieLengths[bessieIndex] - bessiePosition);

        // Check if Bessie is speeding
        if (bessieSpeeds[bessieIndex] > roadSpeeds[roadIndex]) {
            maxOverSpeed = max(maxOverSpeed, bessieSpeeds[bessieIndex] - roadSpeeds[roadIndex]);
        }

        roadPosition += minDistance;
        bessiePosition += minDistance;

        // Move to the next segment if needed
        if (roadPosition == roadLengths[roadIndex]) {
            roadIndex++;
            roadPosition = 0;
        }
        if (bessiePosition == bessieLengths[bessieIndex]) {
            bessieIndex++;
            bessiePosition = 0;
        }
    }

    fout << maxOverSpeed << endl;

    return 0;
}

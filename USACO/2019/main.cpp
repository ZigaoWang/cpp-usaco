#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");

    int K, N;
    fin >> K >> N;

    int sessions[10][20]; // Adjusted according to the problem constraints

    // Reading the rankings
    for (int i = 0; i < K; ++i)
        for (int j = 0; j < N; ++j)
            fin >> sessions[i][j];

    int consistent_pairs = 0;

    // Comparing each pair of cows
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            if (a == b) continue; // Skip same cow comparison

            bool all_sessions_consistent = true;

            // Check all sessions for consistency of this pair
            for (int k = 0; k < K; ++k) {
                int posA, posB;
                for(int pos = 0; pos < N; pos++) { // finding positions of a and b
                    if (sessions[k][pos] == a) posA = pos;
                    if (sessions[k][pos] == b) posB = pos;
                }

                if (posA > posB) { // If A is not consistently better than B
                    all_sessions_consistent = false;
                    break;
                }
            }

            if (all_sessions_consistent) consistent_pairs++;
        }
    }

    // Writing the result to the output file
    fout << consistent_pairs << endl;

    return 0;
}

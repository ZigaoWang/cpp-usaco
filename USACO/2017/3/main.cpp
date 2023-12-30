#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

struct Cow {
    int arrival_time;
    int question_time;
};

bool compare_cows(const Cow& cow1, const Cow& cow2) {
    return cow1.arrival_time < cow2.arrival_time;
}

int main() {
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    int N;
    fin >> N;
    Cow cows[100];

    for (int i = 0; i < N; i++) {
        fin >> cows[i].arrival_time >> cows[i].question_time;
    }

    sort(cows, cows + N, compare_cows);

    int current_time = 0;

    for (int i = 0; i < N; i++) {
        if (current_time <= cows[i].arrival_time) {
            current_time = cows[i].arrival_time + cows[i].question_time;
        } else {
            current_time += cows[i].question_time;
        }
    }

    fout << current_time << endl;

    return 0;
}

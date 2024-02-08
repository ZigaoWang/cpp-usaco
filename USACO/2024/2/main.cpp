//#include <iostream>
//using namespace std;
//
//int jump(int N, int x, int move, bool right) {
//    int res = 0;
//    bool finish = false;
//    // to check if bessie go out the boundaries
//    if (right) {
//        // if yes, finish
//        if (x + move > N) {
//            finish = true;
//        }
//        // else move position
//        else {
//            res = x + move;
//        }
//    }
//    else if (!right) {
//        // if yes, finish
//        if (x - move < 1) {
//            finish = true;
//        }
//        // else move position
//        else {
//            res = x - move;
//        }
//    }
//    if (finish) {
//        return -1;
//    }
//    else {
//        return res;
//    }
//}
//
//int main() {
//    int N = 0, S = 0;
//    cin >> N >> S;
//    int type[10000] = {0};
//    int power[10000] = {0};
//    for (int i = 1; i <= N; i++) {
//        cin >> type[i] >> power[i];
//    }
//    int breakCount = 0;
//    int zeroCount = 0;
//    // initialize jump
//    int currentPosition = S;
//    int currentPower = 1;
//    bool currentDirection = true;
//    for (; currentPosition <= N && currentPosition >= 1;) {
//        cout << currentPosition << " " << currentPower << " " << currentDirection << " " << breakCount << endl;
//        if (type[currentPosition] == 0) {
//            currentPower += power[currentPosition];
//            currentDirection = !currentDirection;
//        }
//        else if (type[currentPosition] == 1) {
//            if (currentPower >= power[currentPosition] && power[currentPosition] != -1) {
//                breakCount++;
//                power[currentPosition] = -1;
//            }
//        }
//        currentPosition = jump(N, currentPosition, currentPower, currentDirection);
//        // check 2 zeros
//        for (int k = 0; k < N; k++) {
//            if (power[k] == 0) {
//                zeroCount++;
//            }
//        }
//        // if yes, then if is infinite
//        if (zeroCount >= 2) {
//            break;
//        }
//    }
//    cout << "End: " << " " << currentPosition << " " << currentPower << " " << currentDirection << " " << breakCount << endl;
//    cout << "Result: " << breakCount;
//    return 0;
////    for (int i = 0; i < N; i++) {
////        // if bessie lands on target
////        if (type[i] == 1) {
////            if (currentPower >= power[i] && power[i] != -1) {
////                breakCount++;
////                power[i] = -1;
////            }
////            if (jump(N - 1, currentPosition, currentPower, currentDirection) != -1) {
////                currentPosition = jump(N - 1, currentPosition, currentPower, currentDirection);
////            }
////            else {
////                // out of bound
////                cout << breakCount << endl;
////                break;
////            }
////        }
////        // if bessie lands on jump pad
////        if (type[i] == 0) {
////            if (jump(N - 1, currentPosition, currentPower, currentDirection) != -1) {
////                currentPosition = jump(N - 1, currentPosition, currentPower, currentDirection);
////            }
////            else {
////                // out of bound
////                cout << breakCount << endl;
////                break;
////            }
////            currentPower += power[i];
////            currentDirection = !currentDirection;
////        }
////    }
//}
//
//

#include <iostream>
using namespace std;

const int MAX_N = 10e5 + 50;

int makeJump(int N, int x, int move, bool right) {
    if (right) {
        return (x + move > N) ? -1 : x + move;
    } else {
        return (x - move < 1) ? -1 : x - move;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    int type[MAX_N], power[MAX_N];

    for (int i = 1; i <= N; i++) {
        cin >> type[i] >> power[i];
    }

    int breakCount = 0;
    int zeroCount = 0;
    int currentPosition = S;
    int currentPower = 1;
    bool currentDirection = true;

    while (currentPosition <= N && currentPosition >= 1) {
        if (type[currentPosition] == 0) {
            currentPower += power[currentPosition];
            currentDirection = !currentDirection;
        } else if (currentPower >= power[currentPosition] && power[currentPosition] != -1) {
            breakCount++;
            power[currentPosition] = -1;
        }
        currentPosition = makeJump(N, currentPosition, currentPower, currentDirection);
        if (power[currentPosition] == 0) {
            zeroCount++;
        }
        if (zeroCount >= 10000) {
            break;
        }
    }

    cout << breakCount;

    return 0;
}

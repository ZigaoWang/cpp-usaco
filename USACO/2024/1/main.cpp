//#include <iostream>
//#include <algorithm>
//using namespace std;
//int type[1000];
//int main() {
//    int test = 0;
//    cin >> test;
//    int num = 0;
//    for (int i = 0; i < test; i++) {
//        cin >> num;
//        int temp[1000] = {0};
//        for (int j = 1; j <= num; j++) {
//            cin >> type[j];
//            if (j > 1 && type[j] == type[j - 1]) {
//                temp[type[j]] = 1;
//            }
//            if (j > 2 && type[j] == type[j - 2]) {
//                temp[type[j]] = 1;
//            }
//        }
//        int possible = false;
//        int place = 0;
//        for (int k = 1; k <= num; k++) {
//            if (temp[k] == 1) {
//                place++;
//                if (place != 1) {
//                    cout << " ";
//                }
//                cout << k;
//                possible = true;
//            }
//        }
//        if (possible == false) {
//            cout << "-1";
//        }
//        cout << endl;
////        sort(temp, temp + num);
////        for (int j = 0; j < num; j++) {
////            if (temp[j] != 0) {
////                cout << temp[j];
////                if (j < num - 1) {
////                    cout << " ";
////                }
////            }
////            if (temp[0] == 0 && temp[num - 1] == 0) {
////                cout << "-1";
////            }
////            while (temp[j] == temp[j + 1]) {
////                j++;
////            }
////        }
////        cout << endl;
//    }
//
//
//    return 0;
//}

#include <iostream>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

const int MAX_ELEMENTS = 1e5 + 50;

int test_cases;
int array_size;
int elements[MAX_ELEMENTS];

int findDuplicate(int start, int end) {
    map<int, int> elementCount;
    for (int i = start; i <= end; ++i) {
        elementCount[elements[i]]++;
        if (elementCount[elements[i]] >= 2) {
            return elements[i];
        }
    }
    return -1;
}

int main() {
    cin >> test_cases;
    while (test_cases--) {
        cin >> array_size;
        for (int i = 1; i <= array_size; ++i) {
            cin >> elements[i];
        }

        if (array_size == 1) {
            cout << elements[1] << endl;
        } else {
            set<int> duplicateElements;
            for (int i = 1; i + 1 <= array_size; ++i) {
                int duplicate = findDuplicate(i, i + 1);
                if (duplicate != -1) {
                    duplicateElements.insert(duplicate);
                }
            }

            for (int i = 1; i + 2 <= array_size; ++i) {
                int duplicate = findDuplicate(i, i + 2);
                if (duplicate != -1) {
                    duplicateElements.insert(duplicate);
                }
            }

            if (duplicateElements.empty()) {
                cout << -1 << endl;
            } else {
                int isFirst = 0;
                for (int duplicate : duplicateElements) {
                    if (isFirst == 1) {
                        cout << " " << duplicate;
                    } else {
                        cout << duplicate;
                    }
                    isFirst = 1;
                }
                cout << endl;
            }
        }
    }
    return 0;
}


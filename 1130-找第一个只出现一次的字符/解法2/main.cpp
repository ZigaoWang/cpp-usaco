#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5+10;
int num[30];
int main(){
    char s[N];
    cin.get(s, N);
    for (int i = 0; i < strlen(s); i++){
        num[s[i] - 'a'] += 1;
    }
    bool f = true;
    for (int i = 0; i < strlen(s); i++){
        if (num[s[i] - 'a'] == 1) {
            f = false;
            cout << s[i];
            break;
        }
    }
    if (f) {
        cout << "no";
    }
    return 0;
}
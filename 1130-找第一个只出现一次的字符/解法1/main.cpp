// 1130：找第一个只出现一次的字符
// 解法 1
#include <iostream>
using namespace std;
const int N = 100000;
int num[30];
int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        num[s[i]-'a'] += 1;
    }

    for(int i = 0; i < s.size(); i++){
        if(num[s[i] - 'a'] == 1){
            cout << s[i];
            return 0;
        }
    }
    cout << "no";

    return 0;
}
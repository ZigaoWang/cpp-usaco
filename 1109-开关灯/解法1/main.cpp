// 1109：开关灯
// 解法 1
#include <iostream>

using namespace std;

int main() {
    int lamp, human, i;
    cin >> lamp >> human;
    int lampSwitch[5000] = {0};
    for (int currentHuman = 1; currentHuman <= human; ++currentHuman) {
        switch (currentHuman) {
            case 1:
                // 第一个人将灯全部关闭
                for (int i = 0; i < lamp; ++i) {
                    lampSwitch[i] = 0;
                }
                break;
            case 2:
                // 第二个人将编号为2的倍数的灯打开
                for (int i = 1; i <= lamp; ++i) {
                    if (i % 2 == 0) {
                        lampSwitch[i - 1] = 1; // 灭变亮
                    }
                }
                break;
            default:
                // 后续的人将自己编号的倍数的灯进行相反处理
                for (int i = 1; i <= lamp; ++i) {
                    if (i % currentHuman == 0) {
                        lampSwitch[i - 1] = !lampSwitch[i - 1]; // 状态取反
                    }
                }
                break;
        }
    }
    bool first = true;
    for (int i = 0; i < lamp; ++i) {
        if (lampSwitch[i] == 0) {
            if (!first) {
                cout << ",";
            }
            cout << i + 1;
            first = false;
        }
    }
    return 0;
}
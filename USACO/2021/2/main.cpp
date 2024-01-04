#include <iostream>
#include <algorithm>
using namespace std;

int a[10];

int main(){
    for(int i=1;i<=7;++i)
        cin >> a[i];
    sort(a+1,a+7+1);
    cout << a[1] << " ";
    cout << a[2] << " ";
    cout << a[7]-a[1]-a[2] << endl;
    return 0;
}
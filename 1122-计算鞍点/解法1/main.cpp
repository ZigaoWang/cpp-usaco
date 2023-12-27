// 1122：计算鞍点
// 解法 1：https://cloud.tencent.com/developer/article/1084017
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define max_ 0x7fff

int a[1001][1001];
int maxn[1001];
int minn[1001];

int main()
{
    for(int i=1; i<=1001; i++)
        minn[i] = 100001;

    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
        {
            cin >> a[i][j];

            if(a[i][j] > maxn[i])
                maxn[i] = a[i][j];

            if(a[i][j] < minn[j])
                minn[j] = a[i][j];
        }
    }

    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
        {
            if((a[i][j] == maxn[i]) && (a[i][j] == minn[j]))
            {
                cout << i << " " << j << " " << a[i][j];
                return 0;
            }
        }
    }

    cout << "not found";
    return 0;
}

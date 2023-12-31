#include<stdio.h>

int main()
{
    int l,r;
    while(scanf("%d%d",&l,&r)!=EOF)
    {
        int t=0;
        for(int i=l; i<=r; i++)
        {
            int j=i;//因为里面的for会改变便外围i的值，所以一定要记得换个变量进去
            for( ; j>0;j/=10)
            {
                int q=j%10;
                if(q==7)
                {
                    t++;
                }
            }
        }
        printf("%d\n",t);
    }
    return 0;
}

/*
问题 G: 22-输入输出-3-7出现的次数
[命题人 : 219127]
时间限制 : 1.000 sec  内存限制 : 128 MB

题目描述
题主是厂长粉丝，对7情有独钟，现在想统计某个给定范围[L, R]的所有整数中数字7出现的次数。
比如给定范围 [66,77]，数字7在数67中出现了1次，在70到76中各出现一次，在数77中出现2次，所以数字7在该范围内一共出现了10次。
输入
多组样例，每个测试样例一行，每行为两个正整数L、R。（0<L<R<10^5）
输出
7出现的次数。
样例输入 Copy
66 77
1 10
样例输出 Copy
10
1
*/
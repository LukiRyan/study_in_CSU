#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct csu
{
    char t[25];
    int jing;
    int sum;
}team[100],t;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int  x,y;
        for(int pp=0; pp<n*(n-1)/2; pp++)
        {
            int ch,i=0;
            while((ch=getchar())!=':')
            {//�ڶ��뻻�з�ʱ������ֹ�������ǿո�
                if(i < n)
                {
                    team[pp].t[i++]=ch;
                }
            }
            scanf("%s",team[pp].t[i++]);
            scanf(" %d:%d",&x,&y);
        }
        
    }
    return 0;
}
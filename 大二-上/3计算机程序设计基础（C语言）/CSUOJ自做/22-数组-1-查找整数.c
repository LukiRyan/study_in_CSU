#include<stdio.h>

int find(int a[],int sz,int x);

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[1000];
        for(int i=0; i<n; i++)
            {
                scanf("%d",&a[i]);
            }
        int x;
        scanf("%d",&x);

        int xiabiao=find(a,n,x);

        printf("%d\n",xiabiao);
    }
    return 0;
}

int find(int a[],int sz,int x)
{//������a������x������sz������Ĵ�С��һ��Ҫ�ڵ��˺���ǰ���
    int key;
    for(int i=0; i<sz; i++)
    {
        if(x==a[i])
        {
            key=i+1;
            break;
        }
        else
        {
            if(i==sz-1)
            {
                key=-1;
                break;
            }
        }
    }
    return key;
}//key����x��(�±�+1)�����еĵڼ�������û�ѵ��������-1


/*
����Ŀ���ʣ�
�������������ƥ�䵽��Ԫ�ص��±꣬��

#include<stdio.h>

void find(int a[],int sz,int x);

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[1000];
        for(int i=0; i<n; i++)
            {
                scanf("%d",&a[i]);
            }
        int x;
        scanf("%d",&x);

        find(a,n,x);
    }
    return 0;
}


//��Ԫ�ظ���Ϊsz������a����Ԫ��x������ӡԪ��x���±�key��
//����sz������Ĵ�С��һ��Ҫ�ڵ��˺���ǰ���

void find(int a[],int sz,int x)
{
    int key;
    int flag=0;
    for(int i=0; i<sz; i++)
    {
        if(x==a[i])
        {
            key=i;
            flag=1;
            printf("%d ",key);
        }
        else
        {
            if(i==sz-1 && flag==0)
            {
                key=-1;
                printf("-1\n");
            }
            if(i==sz-1 && flag==1)
            {
                printf("\n");
            }
        }
    }
}//key����x��(�±�+1)�����еĵڼ�������û�ѵ��������-1
*/
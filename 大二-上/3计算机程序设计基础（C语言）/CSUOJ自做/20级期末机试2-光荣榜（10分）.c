#include<stdio.h>
  
struct csu
{
    char name[11];
    int y;
    int s;
    int w;
    int sum;
}stu[101],t;
  
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s %d %d %d",
            stu[i].name, &stu[i].y, &stu[i].s, &stu[i].w);
            stu[i].sum = stu[i].y + stu[i].s + stu[i].w;
        }
        //
        for(int i=0; i<n-1; i++)//�����˸��������������㷨�ϣ�������
        {
            for(int j=i+1; j<n; j++)
            {
                if(stu[i].sum < stu[j].sum)
                {
                    t=stu[i];
                    stu[i]=stu[j];
                    stu[j]=t;
                }
                if(stu[i].sum == stu[j].sum)
                {
                    for(int k=0; ;k++)
                    {
                        if(stu[i].name[k] > stu[j].name[k])
                        {
                            t=stu[i];
                            stu[i]=stu[j];
                            stu[j]=t;
                            break;
                        }
                        else if(stu[i].name[k] < stu[j].name[k])
                        {
                            break;
                        }
                    }
                }
            }
        }
        for(int i=0; i<3; i++)
        {
            printf("%s %d\n", stu[i].name, stu[i].sum);
        }
        printf("\n");
        //
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(stu[i].y < stu[j].y)
                {
                    t=stu[i];
                    stu[i]=stu[j];
                    stu[j]=t;
                }
                if(stu[i].y == stu[j].y)
                {
                    for(int k=0; ;k++)
                    {
                        if(stu[i].name[k] > stu[j].name[k])
                        {
                            t=stu[i];
                            stu[i]=stu[j];
                            stu[j]=t;
                            break;
                        }
                        else if(stu[i].name[k] < stu[j].name[k])
                        {
                            break;
                        }
                    }
                }
            }
        }
        for(int i=0; i<3; i++)
        {
            printf("%s %d\n", stu[i].name, stu[i].y);
        }
        printf("\n");
        //
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(stu[i].s < stu[j].s)
                {
                    t=stu[i];
                    stu[i]=stu[j];
                    stu[j]=t;
                }
                if(stu[i].s == stu[j].s)
                {
                    for(int k=0; ;k++)
                    {
                        if(stu[i].name[k] > stu[j].name[k])
                        {
                            t=stu[i];
                            stu[i]=stu[j];
                            stu[j]=t;
                            break;
                        }
                        else if(stu[i].name[k] < stu[j].name[k])
                        {
                            break;
                        }
                    }
                }
            }
        }
        for(int i=0; i<3; i++)
        {
            printf("%s %d\n", stu[i].name, stu[i].s);
        }
        printf("\n");
        //
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(stu[i].w < stu[j].w)
                {
                    t=stu[i];
                    stu[i]=stu[j];
                    stu[j]=t;
                }
                if(stu[i].w == stu[j].w)
                {
                    for(int k=0; ;k++)
                    {
                        if(stu[i].name[k] > stu[j].name[k])
                        {
                            t=stu[i];
                            stu[i]=stu[j];
                            stu[j]=t;
                            break;
                        }
                        else if(stu[i].name[k] < stu[j].name[k])
                        {
                            break;
                        }
                    }
                }
            }
        }
        for(int i=0; i<3; i++)
        {
            printf("%s %d\n", stu[i].name, stu[i].w);
        }
        printf("\n");
    }
    return 0;
}

/*
���� O: 20����ĩ����2-���ٰ�10�֣�
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
����CC�����ڵİ༶������һ�����׿��ԣ����Կ�Ŀ�������ġ���ѧ��Ӣ�ﹲ���š�
����CC������ʦ�����˳ɼ����г��˳ɼ��������а���ÿ��ͬѧ�����������ƣ����ġ���ѧ��Ӣ��ĳɼ��������Ƴɼ����ܷ֡�������ʦϣ������һ��ÿ�ſγ̿��Ե÷�ǰ�������ܷ�ǰ������ͬѧ��ͬ����������£������ֵ����С����ǰ�档
���������ʦдһ�����򣬿�������������ɡ�
����
�����������ԣ�ÿ�������ĵ�һ��Ϊһ��������n��3��n��100��������n��ͬѧ��
��������n�ж�Ӧn��ͬѧ�������Ϣ��ÿһ�а���ͬѧ������s��1��s��10�����������������������ֱ������Ǹ������ġ���ѧ��Ӣ�����ſ�Ŀ��Ӧ�ķ���g��0��g��100����

���
���ÿ�ſ��Ե�ǰ���������֣�����Ӧ�ķ�����ÿ��ѧ������Ϣ��ռһ�У�ÿ�ư����и����������ܷ֣����ģ���ѧ��Ӣ���˳�������
ÿ���������������֮���һ�У���������� ��
�������� Copy
4
alice 80 70 60
bob 99 87 55
eric 100 30 99
lily 70 80 66
5
aaa 80 90 100
bbb 87 99 63
ccc 45 65 76
ddd 88 89 92
eee 99 87 95
������� Copy
bob 241
eric 229
lily 216

eric 100
bob 99
alice 80

bob 87
lily 80
alice 70

eric 99
lily 66
alice 60

eee 281
aaa 270
ddd 269

eee 99
ddd 88
bbb 87

bbb 99
aaa 90
ddd 89

aaa 100
eee 95
ddd 92
*/
#include<stdio.h>

int main()
{
    char a[40];
    while(gets(a)!=NULL)
    {
        for(int i=0; i<40; i++)
        {
            if(a[i]=='e' || a[i]=='r' || a[i]=='n')
            {
                a[i]-=32;
            }
            if(a[i]=='M' || a[i]=='I' || a[i]=='K' || a[i]=='A' || a[i]=='S')
            {
                a[i]+=32;
            }
        }
        puts(a);
    }
    return 0;
}

/*
���� F: 22-��������-1-�ض���ĸ��Сд
[������ : 219127]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
Eren��mikasa֮��ӵ��ǿ�ҵ�����ڶ��ڸ���������һ���ַ�����Ҫ��e��r��n��������ĸ��д��ԭ�����Ǵ�д���򱣳ֲ��䣻��m��i��k��a��s����
����ĸСд��ԭ������Сд���򱣳ֲ��䡣
����
����������ÿ����������һ�У�ÿ��Ϊһ���ַ��������ַ�������С��40��
���
��ָ����ĸ���д�Сдת��֮��Ľ����
�������� Copy
bhFjbhFNdnknjk./]��]��gfjdsfnmv
ErEnJaegerMikasaAckerman
ereMIKAS
EREmikas
������� Copy
bhFjbhFNdNkNjk./]��]��gfjdsfNmv
ERENJaEgERmikasaackERmaN
EREmikas
EREmikas
*/
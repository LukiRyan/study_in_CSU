#include<stdio.h>
#include<stdlib.h>

void add2list(struct node *list, int n);

struct node
{
    int data;
    struct node *next;//˵��next(��ַ)�ܹ��洢һ��ָ��struct node���͵�ָ��
}headnode;

int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        while(n--)
        {
            void add2list(heanoed, n);
        }

        struct node *p;
        while(1)
        {
            p+=m;
            printf("%d",*p);
        }
    }
    return 0;
}

//�� ��ַwhichnode ��������µ�������ֵΪthing
void add2list(struct node *whichnode, int thing)
{
    /*��Ҫ��ϣ�ʹ��
    struct node
    {
    int data;
    struct node *next;
    };
    */
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    if(newnode==NULL){exit(EXIT_FAILURE);}//���ù�����ɶ
    newnode->data=thing;
    newnode->next=whichnode;
    *whichnode=*newnode;
}
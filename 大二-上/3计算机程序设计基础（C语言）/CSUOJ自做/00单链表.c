#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createHead();
struct Node* creatNode(int data);
void printList(struct Node* headNode);
void insertNodeByHead(struct Node* headNode, int data);
void insertNodeByTail(struct Node* headNode, int data);

//
int main()
{
    struct Node* list=createHead();  //��������
    for(int i=1; i<5; i++)
    {
        insertNodeByTail(list, i);
    }
    printList(list);
    system("pause");
    return 0;
}


//������ͷ
struct Node* createHead()
{
    //�ṹ��ָ���ɽṹ�����--��ͨ����̬�ڴ�����: int a=(int)mallloc(����)
    struct Node* headNode=(struct Node*)malloc(sizeof(struct Node));
    //����ʹ��ǰ�����ʼ��
    headNode->next=NULL;//: a.next=��
    return headNode;//����a
}

//�����ڵ�--�����û������ݱ�ɽṹ�����������
struct Node* creatNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//���⣺��ӡ�ڵ�--��׼��һ��ָ��ָ���ͷ����һ�����ж���û��data�������ӡ
void printList(struct Node* headNode)//��ӡ�ĸ�����������˭�ı�ͷ
{
    struct Node* pMove=headNode->next;
    while(pMove!=NULL)
    {
        printf("%d\t",pMove->data);
        pMove=pMove->next;
    }
    printf("\n");
}

//��ͷ�ڵ�����ڵ㣨ͷ�巨��
void insertNodeByHead(struct Node* headNode, int data)
{
    //�����ݱ�ɽṹ�����
    struct Node* newNode=creatNode(data);

    newNode->next=headNode->next;   //�����½ڵ��ָ��ָ��ɽڵ�
    headNode->next=newNode;         //����ͷ�ڵ��ָ��ָ���½ڵ㣬���߲��ɵߵ�
}

//��β�巨��
void insertNodeByTail(struct Node* headNode, int data)
{
    struct Node* newNode=creatNode(data);
    struct Node* tailNode;
    if(data==/*��dataΪ��ֵ����tailNode=headnode��������һֱ�������tailNode=newNode*/1)
    {
        tailNode=headNode;
    }
    newNode->next=NULL;
    tailNode->next=newNode;
    tailNode=newNode;
}

//
// void insertNodeByTrall(struct Node *List,int data)
// {
//     struct Node *lastNode = endofList(List);
//     struct Node *newNode  = createNode(data);
//     lastNode->next = newNode;
// }
// struct Node* endofList(struct Node *List)
// {
//     while(List->next) List = List->next;
//     return List;
// }
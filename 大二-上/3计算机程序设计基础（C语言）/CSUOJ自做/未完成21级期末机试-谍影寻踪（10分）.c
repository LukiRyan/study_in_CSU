#include<stdio.h>

struct inf
{
    int x;
    int y;
    int flag;
}a[100];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int len=2*n;
        for(int i=0; i<len; i+=2)
        {
            scanf("%d,%d->%d,%d",
            &a[2*i].x,&a[2*i].y,&a[2*i+1].x,&a[2*i+1].y);
            a[i].flag=1;
            a[i+1].flag=0;
        }
        for(int i=0; i<len-1; i++)
        {
            for(int j=1; j<len; j++)
            {
                if(a[i].flag!=a[j].flag && a[i].x==a[j].x)
                {
                    ;
                }
            }
        }
    }
    return 0;
}

/*
//��

#include <stdio.h> 
#include <string.h> 
 
struct XXX
{
	int id;
	int name1;
	int name2;
};
//����n��0<n��1000������ʾ�ػ񵽵��鱨��
//�����1001�� 
 
 
 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		struct XXX xunlei[1005]={0};
		int count=0;	//���ж�����Ա
	
		for(int i=0;i<n;i++)
		{
			int Ax,Ay,Bx,By;
			scanf("%d,%d->%d,%d",&Ax,&Ay,&Bx,&By);
			//��һ��ֱ�Ӵ���
			if(i==0)
			{
				xunlei[0].id = Ax;
				xunlei[0].name1 = Ay;
				xunlei[0].name2 =0 ;
				xunlei[1].id = Bx;
				xunlei[1].name1 = By; 
				xunlei[1].name2 =0 ;
				count=2; 
			}
			else
			{
				//���������ݵ�A��B��λ��
				int posA=-1, posB=-1;
				for(int i=0;i<count;i++)
				{
					if(xunlei[i].id==Ax)		//����ҵ��Ѿ����ڵ���Ա������name
					{
						posA=i;
						if(xunlei[i].name1!=Ay)	//�����Ա���������֣���name2����
						{
							xunlei[i].name2=Ay;	
						}
					} 
					if(xunlei[i].id==Bx)		//����ҵ��Ѿ����ڵ���Ա������name
					{
						posB=i;
						if(xunlei[i].name1!=By)	//�����Ա���������֣���name2����
						{
							xunlei[i].name2=By;	
						} 
					}
						
				}
				
				if(posA==-1 && posB!=-1)	//B�Ѵ��ڣ�A�����ڡ�
				{
					//��A����B��ǰ��
					for(int i=count-1;i>=posB;i--)
					{
						xunlei[i+1]=xunlei[i];
					}
					xunlei[posB].id=Ax;
					xunlei[posB].name1=Ay;
					xunlei[posB].name2=0;
					count++;
				}
				
				if(posA!=-1 && posB==-1)	//A����,B������
				{
					//��A����Ķ������ƣ�A�ĺ�����B
					for(int i=count-1;i>=posA+1;i--)
					{
						xunlei[i+1]=xunlei[i];
					}
					xunlei[posA+1].id=Bx;
					xunlei[posA+1].name1=By;
					xunlei[posA+1].name2=0;
					count++;	 
				}
				
				if(posA!=-1 && posB!=-1)
				{
					//���ܾ���������name��,�����Ѿ������ˡ�
				}
				
				if(posA==-1 && posB==-1)
				{
					//û�й���������	
				}
			}
		}
		
		for(int i=0;i<count;i++)
		{
			if(i==0)
			{
				if(xunlei[i].name2==0)
					printf("%d,%d",xunlei[i].id,xunlei[i].name1);
				else
					printf("%d,%d#%d",xunlei[i].id,xunlei[i].name1,xunlei[i].name2); 
			}
			else
			{
				if(xunlei[i].name2==0)
					printf("->%d,%d",xunlei[i].id,xunlei[i].name1);
				else
					printf("->%d,%d#%d",xunlei[i].id,xunlei[i].name1,xunlei[i].name2); 
			}
		}
		printf("\n");
	} 
	 
	return 0;
}
*/
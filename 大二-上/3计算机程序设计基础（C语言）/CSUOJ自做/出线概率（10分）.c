#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
int shuwei(int x);

int main()
{
    char s[30]; 
    int a[30];
    while(scanf("%s",s)!=EOF)
    {
        int sum=0;
        int len=strlen(s);
        for(int i=0; i<len; i++)
        {
            a[i]=s[i]-96;
            a[i]=a[i]*pow((-1),i+1)*pow(10,i+1);
            sum+=a[i];
        }



        if(sum<0)
        {
            sum=(-1)*sum;
            printf("-0.");
            
int lo=shuwei(sum);
            
            int pp[lo];
            for(int i=0; i<lo; i++)
            {
                pp[lo-1-i]=sum%10;
                sum/=10;
            }

            if(lo<=len+1)
            {
                for(int i=0; i<len+1-lo; i++)
                {
                    printf("0");
                }
            

            
                 for(int i=0; i<len-(len+1-lo); i++)
            {
                printf("%d",pp[i]);
            }
            }
            else if(lo>len+1)
            {
                for(int i=0; i<len+1; i++)
            {
                printf("%d",pp[i]);
            }
            }

        }
        else
        {
            printf("0.");
            int lo=shuwei(sum);
            
            int pp[lo];
            for(int i=0; i<lo; i++)
            {
                pp[lo-1-i]=sum%10;
                sum/=10;
            }

            if(lo<=len+1)
            {
                for(int i=0; i<len+1-lo; i++)
                {
                    printf("0");
                }
            

            
                 for(int i=0; i<len-(len+1-lo); i++)
            {
                printf("%d",pp[i]);
            }
            }
            else if(lo>len+1)
            {
                for(int i=0; i<len+1; i++)
            {
                printf("%d",pp[i]);
            }
            }

        }
        printf("\n");

      
    }
    return 0;
}


//��ʵ��0��û��λ������������������0��һλ����ʵս��һ��Ҫע�⣡���� 
int shuwei(int x){
    int i;//��Ϊ���ص�i����i���ܶ�����for���� 
	for(i=0;x!=0;i++)
        x/=10;
    return i;
}
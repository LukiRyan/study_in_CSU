#include<stdio.h>
#include<string.h>

int main()
{
    char n[1002],m[1002];//栽在了这里：为什么是1002而不是1000呢？因为若有两个个1000位的数加，结果由于进位和负号最多会多出两位，所以是1000+2=1002
    while(scanf("%s",n)!=EOF)
    {
        int len=strlen(n);
        //如果有负号，把负号扔了先欠着，输出的时候再说，这里巧用flag
        char flag='+';
        if(n[0] == '-')
        {
            flag='-';
            for(int i=0; i<len; i++)
            {
                n[i]=n[i+1];
            }
            len--;
        }
        //两个数的和（还没进位）
        for(int i=0; i<len; i++)
        {
            m[i]=n[len-1-i];
            m[i]=n[i]+m[i]-48;//第一次栽在了这里，没减去48
        }
        //一般情况下进位
        for(int j=len-1; j>=1; j--)
        {
            if(m[j] > '9')
            {
                m[j]-=10;
                m[j-1]++;
            }
        }
        //因为涉及到位数改变所以单独进位
        if(m[0] > '9')
        {
            m[0]-=10;
            len++;
            for(int i=len-1; i>=1; i--)
            {
                m[i]=m[i-1];
            }
            m[0]='1';
        }
        //（区分正负号的）输出
        if(flag == '-')
        {
            len++;
            for(int i=len-1; i>=1; i--)
            {
                m[i]=m[i-1];
            }
            m[0]='-';
            for(int i=0; i<len; i++)
            {
                printf("%c",m[i]);
            }
        }
        else/*(flag == '+)*/
        {
            for(int i=0; i<len; i++)
            {
                printf("%c",m[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

/*
小南最近在资料上看到了一种叫"反间整数"的构造方法，就是将一个整数n的数字顺序颠倒，然后再加上原先的数就得到了n的"反间整数"。例如，对于给定的整数1325，首先将该整数的数字顺序颠倒，得到5231，然后再加上原先的数1325，我们得到5231+1325=6556就是1325的"反间整数"。注意如果颠倒之后的数字有前缀零，前缀零将会被忽略。例如n?= 100时，颠倒之后是1。聪明的你，能帮他编写一个程序实现"反间整数"的构造吗？
输入
多组样例。每行输入一个样例包括一个整数n（n是一个十进制整数，长度≤1000位)
输出
对于每一个输入的n，输出一个数据，表示n的"反间整数"。每个输出占一行。
样例输入?Copy
-9
100
1325
样例输出?Copy
-18
101
6556
*/

//老师的答案没有我的答案好：
/*
#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int i,j,n,q,d,e,g,f=0;
    char a[1002];   //输入字符串
    char b[1002];   //存放倒置后的字符串
    char c[1002];    //存放相加后的字符串
    while(gets(a)!=NULL) //输入字符数组a
    {
        n=strlen(a);      //字符串长度
        if(a[0]!='-')
        {
            for(i=n-1;i>=0;i--)
            {
                b[n-i-1]=a[i];    //b[0]=a[3]:将a数组倒置存入b中 
            }//b[3]={'5','2','3','1'}
            for(i=n-1;i>=0;i--)
            {
                q=b[i]-'0';       //从最低位开始相加 
                d=a[i]-'0';
                e=(q+d+f)%10;    //f为进位 
                c[i+1]=e+'0';
                g=(q+d+f)/10;     //进位 
                f=g;              //将进位赋值给f 
                if(i==0)
                {
                    c[0]=(f+'0');  //最高位需要额外判断 
                }
            }
            f=0;
            int flag=0;        //判断是不是有效0，为1即为有效 
            for(i=0;i<=n;i++)//防止000321的情况发生
            {
                if(c[i]!='0')
                {
                    flag=1;
                }
                if(flag==1)
                {
                    printf("%c",c[i]);
                }
            }
            printf("\n");
        } 
        else//(a[0]=='-')
        {
            c[0]='-';
            for(i=n-1;i>0;i--)
            {
                b[n-i]=a[i];    //将a数组倒置存入b中 
            }
            for(i=n-1;i>0;i--)
            {
                q=b[i]-'0';       //从最低位开始相加 
                d=a[i]-'0';
                e=(q+d+f)%10;    //f为进位 
                c[i+1]=e+'0';
                g=(q+d+f)/10;     //进位 
                f=g;              //将进位赋值给f 
                if(i==1)
                {
                c[1]=(f+'0');  //最高位需要额外判断 
                }
            }
            f=0;
            int flag=0;        //判断是不是有效0，为1即为有效 
            printf("%c",c[0]);
            for(i=1;i<=n;i++)
            {
                if(c[i]!='0')
                {
                flag=1;
                }
                if(flag==1)
                {
                    printf("%c",c[i]);
                }
            }
            printf("\n");
        }
    } 
    return 0; 
}
*/
#include<bits/stdc++.h>

/*

Iterate through each expression. Ignore all left parentheses.
If you hit a character, push that matrix onto the stack. If you hit a right parenthesis,
 pop the top two matrices from the stack. If their inner dimensions match,
 add the number of multiplications to the running count and push back the new matrix. If not, output "error"



*/



using namespace std;
#define MAXN 28
struct martix
{
    int row;
    int col;
} Martix[MAXN],temp[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char t[2];
        int r,c;
        scanf("%s %d %d",t,&r,&c);
        Martix[t[0]-65].row=r;
        Martix[t[0]-65].col=c;
    }

    char s[2*MAXN];
    while(scanf("%s",s)!=EOF)
    {
        int len,ans=0,flag=1;
        len=strlen(s);
        int top=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                temp[top].row=Martix[s[i]-65].row;
                temp[top].col=Martix[s[i]-65].col;
                ++top;
            }
            else if(s[i]==')'&&top>1) // pop 2 matrices
            {
                if(temp[top-2].col!=temp[top-1].row)
                {
                    flag=0;  // checking
                    break;
                }
                ans+=temp[top-2].row*temp[top-2].col*temp[top-1].col;
                temp[top-2].col=temp[top-1].col;
                top=top-1;  //calculate
            }
        }
        if(flag) printf("%d\n",ans);
        else printf("error\n");
    }
     return 0;
}


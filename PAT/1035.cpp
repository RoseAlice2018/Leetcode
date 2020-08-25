#include<iostream>
using namespace std;
struct user
{
    char username[11];// username
    char password[11];//password
};

int main()
{
    int N;
    scanf("%d",&N);
    user storage[N]; 
    int numberofchange=0;
    int res[N];
    for(int i=0;i<N;i++)
    {
        scanf("%s %s",storage[i].username,storage[i].password);
        // cout<<storage[i].username<<endl<<storage[i].password<<endl;
        // check if need to modify
        int tag=0;
        for(int j=0;storage[i].password[j]!='\0';j++)
        {
            char c=storage[i].password[j];
            if(c=='0')
            {
                tag=1;
                storage[i].password[j]='%';
            }
            if(c=='O')
            {
                tag=1;
                storage[i].password[j]='o';
            }
            if(c=='1')
            {
                tag=1;
                storage[i].password[j]='@';
            }
            if(c=='l')
            {
                tag=1;
                storage[i].password[j]='L';
            }
        }
        if(tag==1)
        {
            res[numberofchange]=i;
            numberofchange++;
        }
            
    }
    if(numberofchange>0)
    {
        printf("%d\n",numberofchange);
        for(int i=0;i<numberofchange;i++)
        {
            printf("%s %s\n",storage[res[i]].username,storage[res[i]].password);
        }
    }
    else
    {
        if(N==1)
        printf("There is 1 account and no account is modified");
        else
        {
            printf("There are %d accounts and no account is modified",N);
        }
        
    }
    
        
   
    
    return 0;
}
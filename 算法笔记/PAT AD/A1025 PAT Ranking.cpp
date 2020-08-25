#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct persongrade
{
   char id[15];//id
   int score;//score
   int locationnumber;//考场号
   int localrank;// rank of location
   int totalrank;// rank of all people
};
bool cmp(persongrade a,persongrade b)
{
    if(a.score!=b.score)
        return a.score>b.score;
    else 
    {
        return strcmp(a.id,b.id)<0;
    }
}
persongrade exam[30010];
int main()
{
    int N;// number of location
    scanf("%d",&N);
    int count=0;
    int count1=1;
    while (N--)
    {
        int begin=count;
        int K;
        scanf("%d",&K);
        //load the input of the test
        for(int i=0;i<K;i++)
        {
            scanf("%s %d",exam[count].id,&exam[count].score);
            exam[count].locationnumber=count1;
            count++;
        }
        // sort the location grade and store
        sort(exam+begin,exam+begin+K,cmp);
        //fill the local rank;
        exam[begin].localrank=1;
        for(int i=begin+1;i<begin+K;i++)
        {
            if(exam[i].score==exam[i-1].score)
                exam[i].localrank=exam[i-1].localrank;
            else
            {
                exam[i].localrank=i-begin+1;
            }            
        }
        count1++;
    }
    
    sort(exam,exam+count,cmp);
    exam[0].totalrank=1;
    for(int i=0;i<count;i++)
        {
            if(exam[i].score==exam[i-1].score)
                exam[i].totalrank=exam[i-1].totalrank;
            else
            {
                exam[i].totalrank=i+1;
            }            
        }
    printf("%d\n",count);
    for(int i=0;i<count-1;i++)
    {
        printf("%s %d %d %d\n",exam[i].id,exam[i].totalrank,exam[i].locationnumber,exam[i].localrank);
    }
    int i=count-1;
    printf("%s %d %d %d",exam[i].id,exam[i].totalrank,exam[i].locationnumber,exam[i].localrank);
    
}
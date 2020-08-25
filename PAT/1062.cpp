#include<iostream>
#include<algorithm>
using namespace std;
struct person
{
    int ID;
    int virtue_grade;
    int talent_grade;
};
bool cmp(person a,person b)
{
    int a_total=a.talent_grade+a.virtue_grade;
    int b_total=b.talent_grade+b.virtue_grade;
    if(a_total==b_total)
    {
        if(a.virtue_grade==b.virtue_grade)
        {
        
        
            return a.ID<b.ID;
        
        }
        else
        {
            return a.virtue_grade>b.virtue_grade;
        }
        
        
    }
    else
    {
        return a_total>b_total;
    }
    
}
int main()
{
    int N,low,high;
    scanf("%d %d %d",&N,&low,&high);
    person Sage[N+1];int countsage=0;
    person notableman[N+1];int countnotable=0;
    person foolman[N+1];int countfool=0;
    person meanman[N+1];int countmean=0;
    int res=N;
    for(int i=0;i<N;i++)
    {
        person temp;
        cin>>temp.ID>>temp.virtue_grade>>temp.talent_grade;
        if(temp.talent_grade>=low&&temp.virtue_grade>=low)
        {
            //first sage
            if(temp.talent_grade>=high&&temp.virtue_grade>=high)
            {
                Sage[countsage++]=temp;
            }
            //second notable
            else if(temp.virtue_grade>=high)
            {
                notableman[countnotable++]=temp;
            }
            else if(temp.virtue_grade>=temp.talent_grade)
            {
                foolman[countfool++]=temp;
            }
            else
            {
                meanman[countmean++]=temp;
            }
            
        }
        else
        {
            res--;
        }
        
    }
    printf("%d\n",res);
    sort(Sage+0,Sage+countsage,cmp);
    for(int i=0;i<countsage;i++)
    {
        printf("%d %d %d\n",Sage[i].ID,Sage[i].virtue_grade,Sage[i].talent_grade);
    }
    sort(notableman,notableman+countnotable,cmp);
     for(int i=0;i<countnotable;i++)
    {
        printf("%d %d %d\n",notableman[i].ID,notableman[i].virtue_grade,notableman[i].talent_grade);
    }
    sort(foolman,foolman+countfool,cmp);
     for(int i=0;i<countfool;i++)
    {
        printf("%d %d %d\n",foolman[i].ID,foolman[i].virtue_grade,foolman[i].talent_grade);
    }
    sort(meanman,meanman+countmean,cmp);
     for(int i=0;i<countmean;i++)
    {
        printf("%d %d %d\n",meanman[i].ID,meanman[i].virtue_grade,meanman[i].talent_grade);
    }
    return 0;
}
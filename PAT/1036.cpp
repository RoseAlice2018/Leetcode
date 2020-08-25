#include<iostream>
using namespace std;
struct student
{
    char name[11];
    char ID[11];
    int grade;
    char gender;
};
int main()
{
    int n;
    cin>>n;
    student test[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %s %d",test[i].name,&test[i].gender,test[i].ID,&test[i].grade);
        // cout<<test[i].name<<" "<<test[i].gender<<" "<<test[i].ID<<" "<<test[i].grade;
    }
    int highestfemale=-1;// 记录成绩
    int female=-1;  //记录编号
    int lowestmale=101; //记录成绩
    int male=-1; //记录编号
    for(int i=0;i<n;i++)
    {
        if(test[i].gender=='F')
        {
            // female
            if(test[i].grade>highestfemale)
            {
                highestfemale=test[i].grade;
                female=i;
            }
        }
        if(test[i].gender=='M')
        {
            //male
            if(test[i].grade<lowestmale)
            {
                lowestmale=test[i].grade;
                male=i;
            }
        }
    }
    if(female==-1)
    {
        cout<<"Absent"<<endl;
    }
    else
    {
        cout<<test[female].name<<" "<<test[female].ID<<endl;
    }
    if(male==-1)
    {
        cout<<"Absent"<<endl;
    }
    else
    {
        cout<<test[male].name<<" "<<test[male].ID<<endl;
    }
    if(female==-1||male==-1)
        cout<<"NA";
    else
    {
        cout<<test[female].grade-test[male].grade;
    }
        
    
    return 0;
}
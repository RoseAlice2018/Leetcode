#include<iostream>
using namespace std;
struct Node
{
    int Address;
    int nextAddress;
    char letter;
    Node* next;
    Node(int Address)
    {
        this->Address=Address;
    }
    Node()
    {

    }
};
int main()
{
    int Address1;
    int Address2;
    int numberOfNodes;
    scanf("%d %d %d",&Address1,&Address2,&numberOfNodes);
    Node test[10];
    for(int i=0;i<numberOfNodes;i++)
    {
        scanf("%d %c %d",&test[i].Address,&test[i].letter,&test[i].next);
    }
    Node* A1=new Node(Address1);
    Node* A2=new Node(Address2);
    for(int i=0;i<numberOfNodes;i++)
    {
        Node* p=new Node();
        
    }

    return 0;
}
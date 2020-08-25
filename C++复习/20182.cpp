#include<iostream>
using namespace std;
class Car
{
    public:
        Car():weight(1000)
        {
            cout<<"Car()"<<endl;
        }
        Car(int nWeight)
        {
            weight=nWeight;
            cout<<"Car(int)"<<endl;
        }
        ~Car(){ cout<<"~Car()"<<endl;}
    private:
        int weight;
};
class House
{
    public:
        House()
        {
            cout<<"House()"<<endl;
            rooms=2;
        }
        House(int nRooms)
        {
            rooms=nRooms;
            cout<<"House(int)"<<endl;
        }
        ~House(){ cout<<"~House()"<<endl;}
    private:
        int rooms;
};
class A
{
    public:
        A(int n):val(n)
        {
            cout<<"A(int)"<<endl;
        }
        virtual ~A()
        {
            cout<<"~A()"<<endl;
        }
    protected:
        int val;
};
class B:public A
{
    public:
        B(int n):A(n),i(j),house(3)
        {
            cout<<"B(int)"<<endl;
            int j=99;
            car =Car(2000);
            cout<<"i="<<i<<endl;
            cout<<"j="<<j<<endl;
        }
        virtual ~B(){cout<<"~B()"<<endl;}
    private:
        int i,j;
        Car car;
        House house;
};
int main()
{
    A* pa=new B(10);
    delete pa;
    return 0;
}
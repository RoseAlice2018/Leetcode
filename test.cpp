#include<iostream>
#include<stack>
#include<stdio.h>
#include<queue>
#include<map>
#include<math.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
long get_a_target_long()
{
    return rand();
}
void test_multimap(long& value)
{
	cout<<"\n test_multimap().........\n";
	map<long,string> c;
	char buf[10];
	clock_t timeStart = clock();
	for(long i=0;i< value ;++i)
	{
		try{
			snprintf(buf,10,"%d",rand());
			//multimap can't use [] as insertion
			c.insert(pair<long,string>(i,buf));
		}
		catch(exception& p)
		{
			cout<<"i="<<i<<" "<<p.what()<<endl;
			abort();
		}
	}
	cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
	cout<<"multimap.size()="<<c.size()<<endl;
	cout<<"multimap.max_size()="<<c.max_size()<<endl;
	
	long target = get_a_target_long();
		timeStart = clock();
	std::map<long,string>::iterator pItem = c.find(target);
		cout<<"c.find(),milli-seconds: "<<(clock()-timeStart)<<endl;
	if(pItem != c.end())
		cout<<"found, value = "<<(*pItem).second << endl;
	else
		cout<<"not found!"<<endl;
}

int main()
{
    long value=1000000;
    test_multimap(value);
    return 0;
}





//the usage of find /find_first_of    by heat_nan  from ZZULI
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1("Hi,every one! I am heat_nan from ZZULI. one");
	string str2("heat_nan");
	int k=str1.find(str2);
	cout<<"The position of 'heat_nan' is "<<k<<endl;
	int k1=str1.find("one");
	cout<<"The postion of the first 'one' is "<<k1<<endl;
	int k2=str1.find("one of",k1+1,3);
	cout<<"The postion of the second 'one' is "<<k2<<endl;
	int k3=str1.find_first_of("aeiou");//here k3=1
    cout<<k3;
	while(k3!=string::npos)      //hint:  here "string::npos"means find failed
	{
        cout<<k3;
		str1[k3]='*';
		k3=str1.find_first_of("aeiou",k3+1);
	}
	cout<<str1<<endl;
	return 0;
 
}
 
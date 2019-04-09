#include<iostream>
#include<ctime>
using namespace std;
int topThree(int array[])
{
	int l[3];
	int temp;
	for(int i=0;i<3;i++)
	{
		for(int k=i+1;k<50;k++)
		{
			if(array[k]>array[i])
			{
				temp = array[i];
				array[i] = array[k];
				array[k] = temp;
			}
		}
		l[i] = array[i];
	}
	cout << "前三个数是 :" ;
	for(int i=0;i<3;i++)
		cout << l[i] << "," ; 
}	
int main()
{
	srand((unsigned)time(NULL));
	int a[50];
	for(int i=0;i<50;i++)
		a[i] = rand();
	topThree(a);
	return 0;
}

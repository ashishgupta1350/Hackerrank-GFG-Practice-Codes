#include<iostream>
using namespace std;

void toh(int n,string s="peg1",string h="peg2",string d="peg3")
{
	if(n==1)
	{
		cout<<"Place : "<<s<<" to "<<d<<endl;
	}
	else{
		toh(n-1,s,d,h);
		toh(1,s,h,d);
		toh(n-1,h,s,d);

	}
}
// dp solution is also good

// arr[n]=arr[n-1] *2 +1;
int main()
{
	int n=3;
	toh(3);
	cout<<endl<<endl;
	toh(4);
	return 0;


}
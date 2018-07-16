#include<stdio.h>
#include<string.h>
int main()
{
	// char arr[5]="hello";
	int arr[][3]={{1,2},{3,4,5},{5}};
	printf("%d %d\n",arr[0][2],arr[1][2] );
	printf("\n");
	float a=0.5;
	float b=0.9;
	if(a && b>0.9)
	{
		printf("Hello\n");
	}
	else{
		printf(5+"Nothing\n");
	}
	string s2="s2";

}
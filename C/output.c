// #include <stdio.h>
 
// // #define R 10
// // #define C 20
 
// // int main()
// // {
// //    int (*p)[R][C];
// //    printf("%d\n",  sizeof(*p));
// //    // getchar();
// //    // int a[100];
// //    int b[100];
// //    // int *a = &b;
// //    int *a=b;

// //    printf("%d",  sizeof(b)); // size of b is 400 but the size of a is 4

   

// //    return 0;
// // }
// int main()
// {
//     int a[5] = {1,2,3,4,5};
//     int *ptr = (int*)(&a+1);
//     printf("%d %d", *(a+1), *(ptr-1));
//     return 0;
// }
// #include <stdio.h>
 
// char *c[] = {"GeksQuiz", "MCQ", "TEST", "QUIZ"};
// char **cp[] = {c+3, c+2, c+1, c};
// char ***cpp = cp;
 
// int main()
// {
//     printf("%s ", **++cpp);
//     printf("%s ", *--*++cpp+3);
//     printf("%s ", *cpp[-2]+3);
//     printf("%s ", cpp[-1][-1]+1);
//     printf("\n%d ", sizeof(cp+1));

//     return 0;
// }

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
 
// void fun(char** str_ref)
// {
//     str_ref++;
// }
 
// int main()
// {
//     char *str = (void *)malloc(100*sizeof(char));
//     strcpy(str, "GeeksQuiz");
//     fun(&str);
//     puts(str);
//     free(str);
//     return 0;
// }
// #include <stdio.h>
// void f(char**);
// int main()
// {
//     char *argv[] = { "ab", "cd", "ef", "gh", "ij", "kl" };
//     f(argv);
//     return 0;
// }
// void f(char **p)
// {
//     char *t;
//     t = (p += sizeof(int))[-1];
//     printf("%s\n", t);
// }


#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int a;
	char res[1000];
	a=10;
	itoa(a,res,2);
	cout<<res<<endl;
	itoa(a,res,8);
	cout<<res<<endl;
	return 0;
}

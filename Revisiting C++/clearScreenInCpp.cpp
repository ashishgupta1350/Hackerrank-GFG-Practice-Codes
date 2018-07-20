// #include<iostream>
// #include <unistd.h>
// using namespace std;
// // #include<windows>
// int main()
// {
// 	// cout<<"This is garbage string"<<flush;

// 	// cout<<endl;
// 	for(int i=0;i<10;i++)
// 	{
// 		for(int j=0;j<30;j++)
// 		{
// 			cout<<".";
// 			// Sleep(25);
// 			usleep(3000);

// 		}
// 		cout<<flush;
// 		system("CLS");

// 	}
// 	system("CLS");
// 	cout<<"Where is the garbage?"<<endl;

// }

// #include<iostream>
// #include<Windows.h>
// #include<conio.h>

// using namespace std;

// void writestring(const char *, short, short, short = 7, short = 0);
// void gotoxy(short, short);

// int main()
// {
	
// 	writestring("My name is not khan", 20, 10, 4, 1);
// 	_getch();
// 	return 0;
// }

// void writestring(const char * str, short col, short row, short color, short pnumber)
// {
// 	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //h is handle of current running program
// 	SetConsoleTextAttribute(h, color); // Text of the screen now have color 4 (RED)

// 	cout << "Page Number : " << pnumber << endl;

// 	while (*str != '\0')
// 	{
// 		gotoxy(col, row);
// 		putchar(*str);
// 		col++;
// 		str++;
// 	}
// }

// void gotoxy(short col, short row)
// {
// 	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// 	COORD position = { col, row };
// 	SetConsoleCursorPosition(h, position);

// }

// #include<iostream>
// #include<conio.h>
// #include<cstdlib>
// #include<string>
// #include<cstring>

// using namespace std;

// char * ntas(char *, int);
// char * ntas(char *, double);

// int main()
// {
// 	char str1[20], str2[20];
// 	ntas(&str1[0], 231.324);
// 	cout << str1 << endl;
// 	return 0;
// }

// char * ntas(char *str, int num)
// {
// 	int i;
// 	for (i = 0; num; i++)
// 	{
// 		str[i] = num % 10 + 48;
// 		num /= 10;
// 	}
// 	str[i] = '\0';//Terminating the string

// 	_strrev(str); /*As the numbers saved in the string are reverse of original number
// 	So we will reverse it back to make it like original.*/
// 	return str;
// }

// char * ntas(char * str, double num)
// {	
// 	int Lint, i;
// 	char lstr[20], rstr[20];
// 	long long Rint;
// 	double fractional;

// 	Lint = int(num);
// 	fractional = num - Lint;
// 	// Separating the integer and fractional part of the real number


// 	Rint = fractional * 10000000000;
// 	while (Rint % 10 == 0)
// 		Rint /= 10;
// 	//Making fractional part, like integer


// 	//storing integer part in lstr;
// 	for (i = 0; Lint; i++)
// 	{
// 		lstr[i] = Lint % 10 + 48;
// 		Lint /= 10;
// 	}
// 	lstr[i] = '\0';
// 	_strrev(lstr);
// 	//putting a decimal after integer part.
// 	strcat(lstr, "."); 

	
// 	//Storing fractional part in rstr.
// 	for (i = 0; Rint; i++)
// 	{
// 		rstr[i] = Rint % 10 + 48;
// 		Rint /= 10;
// 	}
// 	rstr[i] = '\0';
// 	_strrev(rstr);


// 	//Joining lstr to rstr and storing in str.
// 	strcat(lstr, rstr);
// 	strcpy(str, lstr);

// 	return str;
// }

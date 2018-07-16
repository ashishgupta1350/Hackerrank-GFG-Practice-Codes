// //https://www.youtube.com/watch?v=9K4N6MO_R1Y
// // 23 minutes
// // 4th July 2018
// #include<regex>
// #include<string>
// #include<iostream>
// using namespace std;
// // #include<smatch>
// #include<string>
// // void printMatches(string s, regex reg)
// // {
// // 	smatch matches;
// // 	cout<<boolalpha;
// // 	cout<<(1==2)<<endl;
// // 	while(regex_search(s,matches,reg))
// // 	{
// // 		cout<<matches.ready();
// // 		cout<<endl<<matches.size();
// // 		cout<<endl<<matches.str(1)<<endl;
// // 		s=matches.suffix().str();
// // 	}
// // }
// // second way to print matches inside a regular expression
// void PrintMatches2(string str,regex reg){
    
//     // This holds the first match
//     std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
    
//     // Used to determine if there are any more matches
//     std::sregex_iterator lastMatch;
    
//     // While the current match doesn't equal the last
//     while(currentMatch != lastMatch){
//         std::smatch match = *currentMatch;
//         std::cout << match.str() << "\n";
//         currentMatch++;
//     }
//     std::cout << std::endl;
    
// }
// // void printMatches2(string s,regex reg)
// // {
// // 	for(auto it=str)
// // }
// int main()
// {
// 	string s ="The ape was ape.net";
// 	// regex reg("(ape[^ ]?)");// ^ means to ignore anything that is after that 
// 	// printMatches(s,reg);
// 	regex reg2("([^ ]\..)");
// 	PrintMatches2(s,reg2);

// 	return 0;
// }

#include<iostream>
using namespace std;
#include<string>
#include<stack>

void letsStack(string s,int k=3)
{
	stack<char> Stack;
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]=='(')
		{
			Stack.push('(');
		}
		else if(s[i]==')')
		{
			Stack.pop();
		}
		else
		{
			if(Stack.size()-1==k)
			{
				cout<<s[i]<<" ";
			}
		}
		i++;
	}

}
int main()
{
	string s="(8(3(2()())(6(5()())()))(5(10()())(7(13()())())))";
	letsStack(s);
	return 0;
}
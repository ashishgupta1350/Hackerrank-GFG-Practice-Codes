#include <iostream>
using namespace std;
#include<string>
#include<stack>
#include<vector>
int convCharacter(char ch){
    int ascii=ch;
    if(ascii>=48 && ascii<=57){
            // this means an alphabet
          return ascii-'0'; // work done:) 
    }
    else return -1;
}
int eval(float x,float y,char op)
{
    float res;
    switch (op)
    {
    case '+':
      res = x + y;
      break;
    case '-':
      res = x - y;
      break;
    case '*':
      res = x * y;
    case '/':
      res = x / y;
    case '%':
      res = int(x) % int(y);
    case '^':
      res =int(x) ^ int(y);
      break;
    }
    return res;
}

float evalPostfix(vector<char> v, int n){
    stack<float> myStack;
    for(int i=0;i<n;i++)
    {
        // there are characters in the vector
        // convert the characters into numbers.
        char ch=v[i];
        int number=convCharacter(ch);
        if(number>=0){
            // number found.
            myStack.push(number);
        }
        else{
            // pop stack 2 times. Evaluate and push result.
            float a=myStack.top();
            myStack.pop();
            float b=myStack.top();
            myStack.pop();
            // evaluate b+a
            // convert the character to operator!
            // '+' -> + ??
            float ans=eval(b,a,ch);
            myStack.push(ans);
        }
        
    }
    return myStack.top();
    
}

int main() {
	//code
	int tc;
    // cout << "enter tc : ";
    cin >> tc;
    for (int i = 0; i < tc; i++) {
    
    	
    	vector<char> v;
        string s;
        cin>>s;
    	for (int i = 0; s[i]!='\0'; i++)
    	{
            char k;
            k=s[i];
            v.push_back(k);
    	}
        // this gives a vector with all the characters
        int n=s.length();
        cout<<evalPostfix(v,n)<<endl;
      
    }
	return 0;
}
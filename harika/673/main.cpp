#include <iostream>
#include<stack>
using namespace std;
void checkpar(int);
int main()
{
    int n;
    cin>>n;
    checkpar(n);
    return 0;
}
void checkpar(int n)
{
    stack<char> temp;
    int count=0;
    while(count!=n)
    {
        string input;
        cin>>input;
        int i=0;
        while(input[i]!='\0')
        {
            if(input[i]=='('||input[i]=='[')
            {
                temp.push(input[i]);
                i++;
            }
            else if(input[i]==')'||input[i]==']')
            {

                if(input[i]==')' && temp.top()=='(')
                {
                    temp.pop();
                    i++;
                }
                else(input[i]==']' && temp.top()=='[')
                {
                    temp.pop();
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        if(temp.empty())
        {
            cout<<"Yes";
            while(temp.empty())
            {
                temp.pop();
            }
        }
        else
        {
            cout<<"No";
        }
        count++;

    }
}

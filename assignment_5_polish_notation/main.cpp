#include <iostream>
#include <stack>
#define N 21

using namespace std;

int main()
{
    //yza3^x2d*c/wa3^^-y-/g*+==
    char s[]="(y=((((a-b)*2)/d)-1))";
    stack<char> v;

    for (int i=0; i<N; i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*' || s[i]=='^' || s[i]=='=' || s[i]=='(')
        {
            v.push(s[i]);
        }
        else if( s[i]==')')
        {
            while(v.top()!='(')
            {
                cout << v.top() << " ";
                v.pop();
            }
            v.pop();
        }
        else
        {
            cout << s[i] << " ";
        }
    }

    return 0;
}

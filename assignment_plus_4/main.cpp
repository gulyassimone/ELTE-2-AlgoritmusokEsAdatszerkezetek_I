#include <iostream>
#include <stack>

#define N 25

using namespace std;

int main()
{
    stack<char> v;
    stack<char> e;
    bool flag=false;
    char k, l;

    string s="yza3^x2d*c/wa3^^-y-/g*+==";
    for(int i=N-1; i>=0; i--)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='^' || s[i]=='*')
        {
            v.push(s[i]);
            cout << "v.top " << v.top() << endl;
        }
        else
        {
            if(!e.empty() && !(s[i-1]=='+' || s[i-1]=='-' || s[i-1]=='/' || s[i-1]=='^'))
            {
                flag=true;
                cout << "flag tru"<< endl;
            }
            else
            {
                e.push(')');
                cout << "push )"<< endl;
            }
            e.push(s[i]);
            cout << "push " << s[i] << endl;
            if(flag)
            {
                e.push('(');
                cout << "( " << endl;
            }
            if(!v.empty())
            {
                e.push(v.top());
                v.pop();
            }
        }

    }
    while(!e.empty())
    {
        cout << e.top() << " " ;
        e.pop();

    }

    return 0;
}

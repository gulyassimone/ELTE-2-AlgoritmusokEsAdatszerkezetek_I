#include <iostream>
#include <stack>

#define N 25

using namespace std;

int main()
{
    stack<char> v;
    stack<char> e;
    bool flag;

    string s="yza3^x2d*c/wa3^^-y-/g*+==";
    for(int i=N-1; i>=0; i--)
    {
        flag=false;
        if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='^' || s[i]=='*' || s[i]=='=')
        {


            v.push('(');
            cout << v.top() << " " << v.size() ;
            cout << endl;
            v.push(s[i]);
            cout << v.top() << " " << v.size() ;
            cout << endl;
            e.push(')');
        }
        else
        {
            if(i!=N-1 && !(s[i+1]=='+' || s[i+1]=='-' || s[i+1]=='/' || s[i+1]=='*' || s[i+1]=='^' || s[i+1]=='=' ))
            {
                flag=true;
            }
            e.push(s[i]);

            while(!v.empty() && flag && v.top()=='(')
            {
                cout << v.top() << " kivettem " << v.size() ;
                cout << endl;
                e.push(v.top());
                v.pop();

            }
            if(!v.empty())
            {
                cout << v.top() << " KIRAKTAM " << v.size() ;
                cout << endl;
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

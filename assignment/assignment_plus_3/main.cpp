#include <iostream>
#include <stack>

using namespace std;
bool vizsgalat();
int main()
{
    cout << vizsgalat() << endl;

    return 0;
}

bool vizsgalat()
{
    stack <char> v;
    char s[]= "abcd#cba#ba#ab";
    bool hash=false;

    for(int i=0; i<sizeof(s)-1; i++)
    {
        if(s[i]=='#')
        {
            hash=true;
        }
        else if(!hash )
        {
            v.push(s[i]);
            cout <<"beteszem " << s[i] << endl;
        }
        else
        {
            if(s[i]==v.top())
            {
                v.pop();
                cout << "kiveszem az " << s[i] << endl;
            }
            else
            {
                cout << "Nem jo " << endl;
                return v.empty();
            }
        }
        if(v.empty())
        {
            hash=false;
        }
        else
        {
            cout << "Nem ures, a top: " << v.top() << endl;
        }
    }

    if(v.empty())
    {
        cout << "tukros" << endl;
    }
    else
    {
        cout << "nem tukros" << endl;

        cout <<"van meg"<< v.empty()<< endl;
    }

    return v.empty();
}

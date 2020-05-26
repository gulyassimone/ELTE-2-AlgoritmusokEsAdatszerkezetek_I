#include <iostream>

using namespace std;

int main()
{
    int n=5;
    int x[] = {-1,0,-1,-4,-7};
    int y=0, max=x[0], ind1=0,  vind1=0, vind2=0;
    for(int i=0; i<n; i++)
    {
        y=y+x[i];

        cout << x[i] << " " << y << endl;
        if(y>=max)
        {
            vind1=ind1;
            vind2=i;
            max=y;
        }

        if(y<0)
        {
            y=0;
            ind1=i+1;
        }
        cout << y << " "<< max<< " " <<vind1 << " " << vind2 << endl;
    }
    return 0;
}

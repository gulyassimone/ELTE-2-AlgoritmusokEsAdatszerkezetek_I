#include <iostream>
#define N 10
using namespace std;

int a=0;
int b=0;
void kiir(int t[N],int u,int v,string name)
{
    cout << name << " : ";
    for(int i=u; i<v; i++)
        cout << t[i] << ", ";
    cout << endl;
}
void mergeSort(int t[N], int u,int m,int v)
{
    int d=m-u;
    int z[d];
    for(int i=0; i<d; i++)
    {
        z[i]=t[u+i];
    }

    kiir(z,0,d,"z merge kezdet");
    kiir(t,u,v,"t merge kezdet");
    int k=u;
    int j=0,i=m;
    while (i<v &&j<d)
    {
        if(t[i]<z[j])
        {
            t[k]=t[i];
            i++;
        }
        else
        {
            t[k]=z[j];
            j++;
        }
        k++;
        a++;
        kiir(z,0,d,"z merge kozben");
        kiir(t,u,v,"t merge kozben");
    }
    while (j<d)
    {
        t[k]=z[j];
        k++;
        j++;
        b++;
    }
    kiir(z,0,d,"z merge vege");
    kiir(t,u,v,"t merge vege");
}
void ms(int t[N],int u,int v)
{
    if(u<v-1)
    {
        int m=(u+v)/2;
        kiir(t,u,m,"vagas 1");
        kiir(t,m,v,"vagas2");
        ms(t,u,m);
        ms(t,m,v);
        mergeSort(t,u,m,v);

    }
}

void mergeSort(int t[N])
{
    ms(t,0,N);
}

int main()
{
    int t[N]= {10,9,8,7,20,1,14,2,1,0};
    kiir(t,0,N,"kezdet");
    mergeSort(t);
    kiir(t,0,N,"rendezett");
    cout <<a<< " " <<b<< endl;
    return 0;
}

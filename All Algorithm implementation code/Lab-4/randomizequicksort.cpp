#include<bits/stdc++.h>
using namespace std;

int a[100]; // try to use vector
// vector<int> a;


int interchange(int a[],int i,int j)
{
    swap(a[i],a[j]); // you have to follow the manual process provided in algorithm

}
int pivot(int a[],int m,int p)
{
    int j,i,v;
    v=a[m];
    i=m;
    j=p;
    while(i<=j) // condition will be reverse if u convert the do-while loop to while loop
    {
        while(a[i]<=v)
        {
            i++;
        }
        while(a[j]>v)
        {
            j--;
        }
        if(i<j)
        {
            interchange(a,i,j);
        }
    }
    a[m]=a[j];
    a[j]=v;
    return j;
}
void Rquick(int p,int q)
{
    if(p<q)
    {
        if((q-p)>5)
        {
            interchange(a,rand()%(q-p+1)+p,p);

        }
        int j=pivot(a,p,q);
        Rquick(p,j-1);
        Rquick(j+1,q);
    }
}

int main()
{
    int s=10; // static input size here, u can convert it as use input
    srand(time(0)); // if u dont use the line the same random number generate everytime
    for(int i=0; i<s; i++)
    {
        a[i]=rand()%100;
    }
    // print data before sorting
    for(int i=0;i<s; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    Rquick(0,s-1);

    // print data after sorting
    for(int i=0;i<s; i++)
        cout<<a[i]<<" ";
    cout<<endl;


    return 0;
}


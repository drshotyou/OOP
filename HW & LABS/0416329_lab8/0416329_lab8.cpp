#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int c;
    int b1=0;
    int b2=0;
    int n,m;

    cin >> c;

    while(c--)
    {
        b1=0;
        b2=0;

        cin >> n;

        m=n;


        for(int i=0;n>0;i++)
        {
            if (n%2==1)
            {
                b1++;
            }
            n=n/2;
        }

        cout << b1 << " ";


        char str[256];
        sprintf(str, "%d", m);
        int x2;
        sscanf(str, "%x", &m);

        for(int j=0;m>0;j++)
        {
            if (m%2==1)
            {
                b2++;
            }
            m=m/2;
        }

        cout << b2 << endl;

    }

    return 0;
}

#include <iostream>
#define A 1000000

using namespace std;

char n[A];

int main()
{
    int i,j;
    int c=1;
    int s,m;
    int t;

    while(cin >> n)
    {

        cout << "Case " << c << ":\n";
        c++;
        cin >> m;

        while (m--)
        {
            cin >> i >> j;

            if (i > j)
            {
                t=i;
                i=j;
                j=t;
            }

            s = 1;

            for (int x = i; x < j; x++)
            {
                if (n[x] != n[j])
                {
                    s = 0;
                }
            }

            if (s == 1)
            {
                cout << "Yes\n";
            }
            else if (s == 0)
            {
                cout << "No\n";
            }
        }

    }

}

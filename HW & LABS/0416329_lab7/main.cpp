#include <iostream>
#define N 10000

#include <bits/stdc++.h>

using namespace std;

char f[N][N];

int main()
{
    int c, r, d, z;

    cin >> c;

    while (c--)
    {
        int m, n, q;

        cin >> m >> n >> q;

        for (int l= 0; l < m; l++)
        {
            cin >> f[l];
        }
           cout << m << " " << n << " " <<q << endl;

            for (int s = 0; s < q; s++)
            {
              cin >> r >> d;

             z = 1;

            for (int a = 0; a <= m || a <= n; a++)
         {
             int x = 0;

            for (int o = r-a; o <= r+a; o++)
            {
                for (int g = d-a; g <= d+a; g++)
             {
                    if (o < 0 || g < 0 || o >= m || g >= n)
                    {
                        x = 1;
                        break;
                    }
                    if (f[o][g] != f[r][d])
                        x = 1;
                }
            }
            if (x == 0)
            {
                if (z < ((2*a) + 1))
                {
                    z = ((2*a) + 1);
                }
            }
            else
              break;
         }

           cout << z << endl;
        }

    }
    return 0;
}

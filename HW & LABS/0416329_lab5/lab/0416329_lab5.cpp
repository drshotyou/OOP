#include <iostream>

#define A 100

using namespace std;

int main()
{
    int n,q,x;
    int answer[A],cnt;

    cin >> n;

    while (n--)
    {

        cin >> q;
        cnt=0;


        if (q<=1)
        {
            cout << q << endl;
            continue;
        }

        for (x = 9; x >= 2; x--)
        {
            while ( q % x == 0)
            {
                q = q / x;
                answer[cnt++] = x;
            }
        }

        if (q==1)
        {
            for (x=cnt-1; x>=0; x--)
            {
                cout << answer[x];
            }
            cout << endl;
        }
        else
        {
            cout << "-1";
            cout << endl;
        }


    }



}

#include <iostream>
using namespace std;

int main()
{
    int y[] = { -1, -1, 0, 1, 1, 1, 0 ,-1 };
    int x[] = {  0, 1 , 1, 1, 0, -1, -1 ,-1 };

    char board;
    int n,m;
    int fields=1;

    while(cin>>n>>m)
    {
        if (m==0 && n ==0)
        {
            break;
        }

        /*for(int x = 1;x <= n; x++)
        {
            for(int y = 1;y <= m; y++)
            {
                if(mines[x][y]>=9)
                    cout << '*';
                else
                    cout << mines[x][y];
            }
            cout << endl;
        }*/

        int mines[n+2][m+2];

        for(int i = 0;i <= n+1; i++)
        {
            for(int j = 0;j <= m+1; j++)
            {
                mines[i][j] = 0;
            }

        }

        for(int i = 1;i <= n; i++)
        {
            for(int j = 1;j <= m; j++)
            {
                cin>>board;

                if(board == '*')
                {
                    mines[i][j] = 9;
                }

                else if(board == '.')
                {
                    mines[i][j] = 0;
                }

            }
        }
        for(int i = 1;i <= n; i++)
        {
            for(int j = 1;j <= m; j++)
            {
                if(mines[i][j] >= 9)
                {
                    for(int k = 0; k <8 ; k++)
                    {
                    /*  y[] = { -1, -1, 0, 1, 1, 1, 0 ,-1 };
                        x[] = {  0, 1 , 1, 1, 0, -1, -1 ,-1 }; */
                        mines[ i + y[k] ][ j + x[k] ] ++;
                    }
                }
            }
        }

       if(fields != 1)
       cout<<endl;

       /* if(fields != 1)
          cout<<endl;     */


        cout << "Field #" << fields << ":" << endl;

        for(int x = 1;x <= n; x++)
        {
            for(int y = 1;y <= m; y++)
            {
                if(mines[x][y]>=9)
                    cout << '*';
                else
                    cout << mines[x][y];
            }
            cout << endl;
        }
        fields++;
    }
}

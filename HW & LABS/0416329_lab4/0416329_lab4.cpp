#include <iostream>
#include <stdlib.h>

using namespace std;

int a[1000000];

int main()
{
	int x,y;

	while (cin >> x >> y)
    {
        if (x < y || x <= 1)
        {
			cout << "Boring!\n";
			continue;
        }

    int i = 0;

		while (x%y == 0 && x >= y)
        {
			a[i++] = x;
			x = x/y;
		}
		 a[i] = x;

            if (i == 0 || a[i] != 1)
            {
            cout << "Boring!\n";
            }

            else
            {
			for (int z = 0; z < i; ++z)
            {
                cout << a[z] << " ";
                cout << a[i] << endl;
            }


            }
	}
	return 0;
}

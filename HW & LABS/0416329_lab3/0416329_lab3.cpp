#include <iostream>
#include <cstdio>

using namespace std;

const int LIMIT = 1000000;

int reverse( int x )
{
    int y = 0;

    while( x != 0 )
    {
        y *= 10;
        y += x%10;
        x /= 10;
    }
  return y;
}

int main()
{
  bool composite[LIMIT+5] = {true, true};

  for( int a = 2; a <= LIMIT ; ++a )
    {
    if( !composite[a] )
    {
      for( int b = a+a ; b <= LIMIT ; b += a )
      {
        composite[b] = true;
      }
    }
  }

  int N;

  while( cin >> N )
    {
    if( composite[N] )
    {
      //printf( "%d is not prime.\n", N);

      cout << N << " is not prime." << endl;

      continue;
    }

    int reverseN = reverse(N);

    if(reverseN != N && !composite[reverseN])

    {
        // printf( "%d is emirp.\n", N );

        cout << N << " is emirp." << endl;
    }
    else
    {
      //printf( "%d is prime.\n", N );

      cout << N << " is prime. " << endl;
    }

  }
  return 0;
}

#include <iostream>

using namespace std;

int main()
{
    long long int number,input;


    while(cin>>number,number>0)
    {

        while (number>=10)
        {
            input=number;
            number=0;

                while(input>0)
                {
                    number+=input%10;
                    input/=10;
                }

        }

        cout<<number<<endl;
    }

    return 0;
}

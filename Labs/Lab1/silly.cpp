// #include <iostream>

// int main(int argc, char* argv[]){

// }
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        int product = 1;
        for (int i = 1; i < argc; i++)
        {
            product = product * stoi(argv[i]);
        }
        cout << "product of integers:   " << product;
    }
}
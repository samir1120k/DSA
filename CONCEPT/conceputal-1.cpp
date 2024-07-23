#include <iostream>
using namespace std;
int main()
{

    char a = 30;
    char b = 40;
    char c = 10;
    char d = (a * b) / c;
    printf("%d ", d);
    printf("\n");
    int A, B = 10;
    A = -B--;
    printf("A is : %d,B is : %d", A, B);

    return 0;
}
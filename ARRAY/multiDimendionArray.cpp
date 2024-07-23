#include <iostream>
using namespace std;
int main()
{
    // one dimensional array
    // int arr[5];
    // cout << "enter the array :" << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << "array is :" << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    // multidimensional array
    // int arr2[2][3];
    // cout << "enter the 2d array:" << endl;
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> arr2[i][j];
    //     }
    // }
    // cout << " 2d array is  :" << endl;
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << arr2[i][j] << endl;
    //     }
    // }

    // size of array define in run time array

    // multidimensional array has a dynamic size
    int row, col;
    cout << "enter the row and column of 2d array:" << endl;
    cin >> row >> col;
    int arr[row][col];
    cout << "enter the 2d array:" << endl;
  

    return 0;
}
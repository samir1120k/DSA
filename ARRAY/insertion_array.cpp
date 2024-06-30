#include <iostream>
using namespace std;

int insert(int n, int arr[], int x, int pos)
{

    n++;
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    cout << "new array is :";

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}

int main()
{
    int arr[20] = {0};
    int n, x, pos;
    cout << "Enter the size of array:" << endl;
    cin >> n;
    cout << "Enter the element in array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nEnter the value you want to insert:";
    cin >> x;
    cout << "Enter the position you where you want to insert the value:";
    cin >> pos;
    insert(n, arr, x, pos);
    return 0;
}
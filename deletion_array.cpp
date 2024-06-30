#include <iostream>
using namespace std;

// int deletion(int arr[], int n, int key)
// {
// }
int main()
{
  int arr[20] = {0};
  int n, key;
  cout << "Enter the size of array:";
  cin >> n;
  cout << "Enter the element of array:";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << "array is:";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "Enter the value you want to delete:";
  cin >> key;
  // deletion(arr,n,key);
  return 0;
}
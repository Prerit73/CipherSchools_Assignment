#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{

  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[left + i];
  }

  for (int j = 0; j < n2; j++)
  {
    M[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main()
{
  int arr[]= {6, 5, 12, 10, 9, 1};
  int n = 6;

  mergeSort(arr, 0, n - 1);

  cout << "Sorted array " << endl;
  for(int i:arr){
    cout<<i<<" ";
  }
}
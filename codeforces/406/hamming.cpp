# include <iostream>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

using namespace std;

int print_triplets(int arr1[], int arr2[], int m) {

  for (int i = 0; i < m; i++) {
    cout << arr1[i]<< "and" << arr2[i] << endl;
  }
}

int hamming_distance(int bit1, int size1, int bit2, int size2, int n) {
  int diff = abs(size2 - size1);
  int xr = bit1 xor bit2;

  return xr * (n - diff) + (not xr) * (diff);
}

int main() {
  int m, n;

  cin >> n >> m;

  int arr1[m], arr2[m];

  for (int i = 0; i < m; i++) {
    cin >> arr1[i] >> arr2[i];
  }

  //print_triplets(arr1, arr2, m);
  cout << hamming_distance(0, 3, 1, 4, 5);
  cout << hamming_distance(0, 3, 0, 5, 5);
}



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
  //cout << bit1 << " " << size1 << " " << bit2 << " " << size2 << " " << n << endl;
  int diff = abs(size2 - size1);
  int xr = bit1 xor bit2;

  return xr * (n - diff) + (not xr) * (diff);
}

int maximum_hamming(int arr1[], int arr2[], int m, int n) {
  int currentmax = 0;
  int currentnum = 1;
  
  for (int i = 0; i < m; i++) {

    for (int j = 0; j < m && j != i; j++) {

      for (int k = 0; k < m && k != i && k != j; k++) {
        int ij_dist = hamming_distance(arr1[i], arr2[i], arr1[j], arr2[j], n);
        int jk_dist = hamming_distance(arr1[j], arr2[j], arr1[k], arr2[k], n);
        int ki_dist = hamming_distance(arr1[k], arr2[k], arr1[i], arr2[i], n);

        int distance =  ij_dist + jk_dist + ki_dist;
        
        //cout << i << j << "distance: " << ij_dist << endl;
        //cout << j << k << "distance: " << jk_dist << endl;
        //cout << k << i << "distance: " << ki_dist << endl;
        //cout  << "distance: " << distance << endl << endl;

        if (currentmax < distance) {
          currentmax = distance;
          currentnum = 1;
        }
        else if(currentmax == distance) {
          currentnum++;
        }
      }
    }
  }
  
  cout << currentnum;
}

int main() {
  int m, n;

  cin >> n >> m;

  int arr1[m], arr2[m];

  for (int i = 0; i < m; i++) {
    cin >> arr1[i] >> arr2[i];
  }

  //print_triplets(arr1, arr2, m);
  maximum_hamming(arr1, arr2, m, n);
}



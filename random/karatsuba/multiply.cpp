# include <iostream>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <vector>
# include <assert.h>
# include <string>


using namespace std;

int length(int num) {
  return floor(log10(abs(num))) + 1;
}

vector<int> num_to_vec(int num) {
  vector<int> myint;

  while(num > 0) {
    myint.insert(myint.begin(), num%10);
    num = num/10;
  }

  return myint;
}

int print_vector(vector<int> num) {
  string output ("[");
  
  for(vector<int>::iterator it = num.begin(); it != num.end(); ++it) {
    /* std::cout << *it; ... */
    output = output + std::to_string(*it);
  }
  
  ouput = output + "]";
  return output;
}

int karatsuba(vector<int> num1, vector<int> num2) {
  int len1 = num1.size();
  int len2 = num2.size();

  // no point karatsubaing if anyone is less than 10
  /*if(num1 < 10 || num2 < 10)
    printf("%d and %d\n", num1, num2);
*/
  int n = max(len1, len2);

  // pad zeros and print vectors
  printf("%s\n", print_vector(num1));

  int mid = ceil((n+1)/2);
  printf("n: %d mid: %d\n", n, mid);
}

int main() {
  int num1, num2, result;
  cin >> num1 >> num2;

  vector<int> num1_vec = num_to_vec(num1);
  vector<int> num2_vec = num_to_vec(num2);

  karatsuba(num1_vec, num2_vec);
  
  //print_vector(num1_vec);
  
  // statistical assertion testing here
  //assert(1==2);
}



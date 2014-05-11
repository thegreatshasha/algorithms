# include <iostream>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <vector>
# include <assert.h>
# include <string>
# include <sstream>


using namespace std;

int length(int num) {
  return floor(log10(abs(num))) + 1;
}

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

vector<int> num_to_vec(int num) {
  vector<int> myint;

  while(num > 0) {
    myint.insert(myint.begin(), num%10);
    num = num/10;
  }

  return myint;
}

vector<int> pad_zeros(vector<int> num, int length) {
  if(num.size() < length) {
    while(num.size() < length) {
      num.insert(num.begin(), 0);
    }
  }

  return num;
}

string print_vector(vector<int> num, int start, int end) {
  string output ("[");
  
  /*for(vector<int>::iterator it = num.begin(); it != num.end(); ++it) {
    output = output + convertInt(*it);
  }*/

  for(int i = start; i <= end; ++i) {
    output = output + convertInt(num[i]);
  }
  
  output = output + "]";
  return output;
}

int karatsuba(vector<int> num1, vector<int> num2, int num1_start, int num2_start, int num1_end, int num2_end) {
  // no point karatsubaing if anyone is less than 10
  /*if(num1 < 10 || num2 < 10)
    printf("%d and %d\n", num1, num2);
*/
  printf("vector1: %s vector2: %s\n", print_vector(num1, num1_start, num1_end).c_str(), print_vector(num2, num2_start, num2_end).c_str());
  // Assumption: num1 and num2 are of equal size

  if(num1_start==num1_end && num2_start==num2_end)
    return num1[num1_start] * num2[num2_start];

  int n = max( num1_end-num1_start , num2_end - num2_start) + 1;

  // pad zeros and print vectors
  
  int mid = n/2 - 1;
  int len = n - mid - 1;

  // call karatsuba again
  printf("n: %d mid: %d\n", n, mid);

  int z1 = karatsuba(num1, num2, num1_start, num2_start, num1_start+mid, num2_start+mid);
  int z2 = karatsuba(num1, num2, num1_start+mid+1, num2_start+mid+1, num1_end, num2_end);

  // calculate the third vector. Make this a separate routine
  vector<int> sub1, sub2;

  int carry1 = 0, carry2 = 0;
  
  for(int i=n-1; i>mid; i--) {
    int n1 = num1[i];
    int n2 = i-len >=0 ? num1[i-len] : 0;

    int n3 = num2[i];
    int n4 = i-len >=0 ? num2[i-len] : 0;
    
    printf("add: %d + %d \n", n1, n2);
    printf("corresponding: \n");
    
    int rez1 = n1 + n2 + carry1;
    int rez2 = n3 + n4 + carry2;
    
    carry1 = rez1/10;
    carry2 = rez2/10;


    sub1.insert(sub1.begin(), rez1%10);
    sub2.insert(sub2.begin(), rez2%10);

  }
  
  if(carry1)
    sub1.insert(sub1.begin(), carry1);

  if(carry2)
    sub2.insert(sub2.begin(), carry2);

  // Equalize sizes
  sub1 = pad_zeros(sub1, max(sub1.size(), sub2.size()));
  sub2 = pad_zeros(sub2, max(sub1.size(), sub2.size()));

  int z3 = karatsuba(sub1, sub2, 0, 0, sub1.size() - 1, sub2.size() - 1);

  int result = 10^n;

  // pad zeroes

  printf("sub vector1 is: %s, sub vector 2 is: %s\n", print_vector(sub1, 0, sub1.size()-1).c_str(), print_vector(sub2, 0, sub2.size()-1).c_str());

  //printf("z1: %d z2: %d\n", z1, z2);
}

int main() {
  int num1, num2, result;
  cin >> num1 >> num2;

  vector<int> num1_vec = num_to_vec(num1);
  vector<int> num2_vec = num_to_vec(num2);

  int n = max( num1_vec.size() , num2_vec.size());

  num1_vec = pad_zeros(num1_vec, n);
  num2_vec = pad_zeros(num2_vec, n);

  karatsuba(num1_vec, num2_vec, 0, 0, num1_vec.size()-1, num2_vec.size()-1);
  
  // statistical assertion testing here
  //assert(1==2);
}



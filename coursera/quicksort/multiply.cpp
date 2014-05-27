# include <iostream>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <vector>
# include <assert.h>
# include <string>
# include <sstream>
# include <fstream>
# include <algorithm>

using namespace std;

/* This is a minimized version of the BigInteger class meant to be
 * used for single file development purposes (such as programming contests).
 * For a complete documentation on what every method does please refer to
 * the class header file 'BigInteger.h'.
 */
class BigInteger {
private:
  string integer;
public:
  BigInteger(unsigned int integer);
  BigInteger(string integer);
  void setInteger(unsigned int integer);
  void setInteger(string integer);
  unsigned int getIntValue() const;
  string toString() const;
  BigInteger addInteger(const BigInteger& integer_to_add) const;
  BigInteger addInteger(const string& integer_to_add) const;
  BigInteger multiplyInteger(const BigInteger& integer_to_multiply) const;
  BigInteger multiplyInteger(const string& integer_to_multiply) const;
  static size_t getTrimIndex(const string& integer);
  bool operator==(const BigInteger& integer) const;
  BigInteger operator+(const BigInteger& integer) const;
  BigInteger operator*(const BigInteger& integer) const;
  friend ostream& operator<<(ostream& in, BigInteger& integer);
};

BigInteger::BigInteger(unsigned int integer) {
  setInteger(integer);
}

BigInteger::BigInteger(string integer) {
  for (int i = 0; i < (int)integer.size() && integer[i] >= '0' && integer[i] <= '9'; i++) {
    this->integer += integer[i];
  }

  if (this->integer.size() == 0) {
    this->integer = "0";
  } else {
    this->integer = integer.substr(getTrimIndex(integer));
  }
}

void BigInteger::setInteger(unsigned int integer) {
  if (integer == 0) this->integer = "0";

  while (integer) {
    this->integer = (char)((integer % 10) + '0') + this->integer;
    integer /= 10;
  }
}

void BigInteger::setInteger(string integer) {
  this->integer = integer;
}

unsigned int BigInteger::getIntValue() const {
  unsigned int ret = 0;
  unsigned int biggest = 0xFFFFFFFF;
  for (int i = 0; i < (int)integer.size(); i++) {
    int unit = integer[i] - '0';
    if (ret > (biggest - unit) / 10.0) return 0;
    ret = ret * 10 + unit;
  }
  return ret;
}

string BigInteger::toString() const {
  return integer;
}

BigInteger BigInteger::addInteger(const BigInteger& integer_to_add) const {
  int a_n = max((int)(integer_to_add.toString().size() - toString().size()), 0);
  int b_n = max((int)(toString().size() - integer_to_add.toString().size()), 0);
  string a = string(a_n, '0') + toString();
  string b = string(b_n, '0') + integer_to_add.toString();

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  string result; int carry = 0;

  for (int i = 0; i < (int)a.size(); i++) {
     int sum = (a[i] - '0') + (b[i] - '0') + carry;
     result += ((char)(sum % 10 + '0'));
     carry = sum / 10;
  }

  if (carry != 0) result += ((char)(carry + '0'));

  reverse(result.begin(), result.end());

  return BigInteger(result.substr(getTrimIndex(result)));
}

BigInteger BigInteger::addInteger(const string& integer_to_add) const {
  return addInteger(BigInteger(integer_to_add));
}

BigInteger BigInteger::multiplyInteger(const BigInteger& integer_to_multiply) const {
  string a = integer_to_multiply.toString();
  string b = toString();

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  BigInteger ret("0");

  for (int i = 0; i < (int)a.size(); i++) {
    int carry = 0; string tmp = string(i, '0');

    for (int j = 0; j < (int)b.size(); j++) {
      int mul = (a[i] - '0') * (b[j] - '0') + carry;
      tmp += ((char)(mul % 10 + '0'));
      carry = mul / 10;
    }

    if (carry != 0) tmp += (carry + '0');

    reverse(tmp.begin(), tmp.end());

    ret = ret.addInteger(tmp.substr(getTrimIndex(tmp)));
  }

  return ret;
}

BigInteger BigInteger::multiplyInteger(const string& integer_to_multiply) const {
  return multiplyInteger(BigInteger(integer_to_multiply));
}

size_t BigInteger::getTrimIndex(const string& integer) {
  size_t index = 0;
  while (integer[index] == '0' && index < integer.size() - 1) index++;
  return index;
}

bool BigInteger::operator==(const BigInteger& integer) const {
  return this->integer == integer.toString();
}

BigInteger BigInteger::operator+(const BigInteger& integer) const {
  return addInteger(integer);
}

BigInteger BigInteger::operator*(const BigInteger& integer) const {
  return multiplyInteger(integer);
}

ostream& operator<<(ostream& in, BigInteger& integer) {
  in << integer.toString();

  return in;
}

















BigInteger comparison_count = 0;
//BigInteger inv_count = 0;

int length(int num) {
  return floor(log10(abs(num))) + 1;
}

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

string print_vector(vector<int> num, int start, int end) {
  string output ("[");
  
  for(int i = start; i <= end; ++i) {
    output = output + convertInt(num[i]) + ",";
  }
  
  output = output + "]";
  return output;
}

vector<int> num_to_vec(int num) {
  vector<int> myint;

  ////printf("%s\n", print_vector(myint, 0, myint.size() - 1).c_str());

  while(num > 0) {
  	int toinsert = num%10;
  	//////printf("Lets insert: %d\n", toinsert);
    myint.insert(myint.begin(), num%10);
    num = num/10;
  }

  ////printf("%s\n", print_vector(myint, 0, myint.size() - 1).c_str());

  return myint;
}



int swap(vector<int> &num, int i, int j) {
	int temp = num[i];
	num[i] = num[j];
	num[j] = temp;
}

int print_level(int level) {
	for(int i=0; i<=level; i++) {
  		printf("\t");
  	}
}

int quick_sort(vector<int> &num, int start, int end, int level) {
  /*for(int i=0; i<=level; i++) {
  	//////printf("\t");
  }*/
  print_level(level);
  printf("{\n\n");

  print_level(level);
  printf("%s: %d\n", print_vector(num, start, end).c_str(), end - start + 1);
  
  /*print_level(level);
  printf("start: %d, end: %d, level: %d\n", start, end, level);*/

  if(start >= end){
    print_level(level);
    printf("base case. exiting\n\n");

    print_level(level);
    printf("}\n\n");
    return 0;
  }

  comparison_count = comparison_count + BigInteger(end - start); 
  print_level(level);
  printf("adding comparisons: ");
  cout << end - start << endl;
  
  // swap pivot position with end
  int pivot_pos = end;
  swap(num, pivot_pos, start);

  // pad zeros and //print vectors
  int pivot_val = num[start];
  int i = start+1;

  for(int j=start+1; j<=end; j++) {
    //print_level(level);
    //printf("comparing %d-%d\n", num[i], num[j]);

    if (num[j] < pivot_val) {
      /*print_level(level);
      printf("Swapping: %d[%d]-%d[%d]\n", num[i], i, num[j], j);*/
      
      swap(num, i, j);

      /*print_level(level);
      printf("%s\n", print_vector(num, start, end).c_str());*/
      i++;
    }
  }

  swap(num, i-1, start);
  print_level(level);
  printf("%s: %d\n", print_vector(num, start, end).c_str(), end - start + 1);

  // now do the recursive calls
  print_level(level);
  printf("calling quickrort from %d[%d]..%d[%d], %d[%d]..%d[%d]. pivot: %d[%d]\n", num[start], start, num[i-2], i-2, num[i], i, num[end], end, num[i-1], i-1);
  
  quick_sort(num, start, i - 2, level+1);
  quick_sort(num, i, end, level+1);
  
  //////printf("mid: %d, left1: %d, right1: %d, left2: %d, right2: %d, len: %d\n", mid, start, start + midleft, midright, end, len);
  /*print_level(level);
  printf("exiting\n\n");*/
  print_level(level);
  printf("}\n\n");
  return 0;

  //////////printf("z1: %d z2: %d\n", z1, z2);
}

int statistical_tests(int n=100) {
  
}

vector<int> read_numbers() {
  vector<int> mynum;

  ifstream iFile("100.txt");        // input.txt has integers, one per line
  
  int x;

  while (iFile >> x) 
  {
      //cerr << x << endl;
      //////printf("%d\n", x);
      mynum.push_back(x);
  }

  return mynum;
}

int main() {
  vector<int> num = read_numbers();
  //////printf("%s: %d\n", print_vector(num, 0, num.size() - 1).c_str(), num.size());
  //vector <int> num = num_to_vec(1234);  

  //swap(num, 0, 1);
  quick_sort(num, 0, num.size()-1, 0);
  //////printf("inversions_count: %d\n", inversion_count);
  cout << comparison_count << endl;

  printf("%s: %d\n", print_vector(num, 0, num.size() - 1).c_str(), num.size());
  // statistical assertion testing here
  //assert(1==2);
}



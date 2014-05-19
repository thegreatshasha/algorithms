# include <iostream>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <vector>
# include <assert.h>
# include <string>
# include <sstream>
# include <fstream>


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

  printf("%s\n", print_vector(myint, 0, myint.size() - 1).c_str());

  while(num > 0) {
  	int toinsert = num%10;
  	printf("Lets insert: %d\n", toinsert);
    myint.insert(myint.begin(), num%10);
    num = num/10;
  }

  printf("%s\n", print_vector(myint, 0, myint.size() - 1).c_str());

  return myint;
}



int swap(vector<int> num, int i, int j) {
	int temp = num[i];
	num[i] = num[j];
	num[j] = temp;
}

int print_space(int level) {
	for(int i=0; i<=level; i++) {
  		printf("\t");
  	}
}

int merge(vector<int> &num, int start1, int end1, int start2, int end2, int level) {
	//print_space(level);
	//printf("Merging: %s[%d--%d] %s[%d--%d]\n", //print_vector(num, start1, end1).c_str(), start1, end1, //print_vector(num, start2, end2).c_str(), start2, end2);
	
	//print_space(level);
	//printf("%d, %d, %d, %d\n", start1, end1, start2, end2);
	
	int count = 0, length = end2 + end1 - start2 - start1 + 2;
	int left = start1;
	int temp[length];

	//print_space(level);
	//printf("succesffully entering %d\n", level);

	while(start1 <= end1 && start2 <= end2) {
		if(num[start1] > num[start2]) {
			temp[count++] = num[start2++];
		}else{
			temp[count++] = num[start1++];
		}
	}

	while(start1<=end1)
		temp[count++] = num[start1++];

	while(start2<=end2)
		temp[count++] = num[start2++];

	
	for(int i=0; i<length; i++) {
		num[left+i] = temp[i];
		//print_space(level);
		//printf("assigning %d: %d\n", i, temp[i]);
	}

	//print_space(level);
	//printf("succesffully returning from: %d\n", level);

}

int sort(vector<int> &num, int start, int end, int level) {
  /*for(int i=0; i<=level; i++) {
  	//printf("\t");
  }*/

  //printf("%s\n", //print_vector(num, start, end).c_str());

  if(start == end)
    return 0;

  // n gives actual length. rest everything is just diff
  int n = end - start + 1;

  // pad zeros and //print vectors
  
  int mid = n/2;
  int even_or_odd = ( n%2 == 0 ? n: n+1 );
  int midleft = even_or_odd/2 -1;
  int midright = even_or_odd/2;
  int len = mid;

  // call karatsuba again
  ////printf("n: %d mid: %d\n", n, mid);

  // calculate the third vector. Make this a separate routine
  

  //for(int i=0; i<=level; i++) {
  //	//printf("\t");
  //}
  ////printf("mid: %d, left1: %d, right1: %d, left2: %d, right2: %d, len: %d\n", mid, start, start + midleft, midright, end, len);
  sort(num, start, start + midleft, level+1);
  sort(num, start + midright, end, level+1);

  merge(num, start, start + midleft, start+midright, end, level);

  /*for(int i=0; i<=level; i++) {
  	//printf("\t");
  }

  //printf("%s\n", //print_vector(num, start, end).c_str());*/
  return 0;

  //////printf("z1: %d z2: %d\n", z1, z2);
}

int statistical_tests(int n=100) {
  
}

vector<int> read_numbers() {
  vector<int> mynum;

  ifstream iFile("IntegerArray.txt");        // input.txt has integers, one per line
  
  int x;

  while (iFile >> x) 
  {
      //cerr << x << endl;
      //printf("%d\n", x);
      mynum.insert(mynum.begin(), x);
  }

  return mynum;
}

int main() {
  vector<int> num = read_numbers();

  sort(num, 0, num.size()-1, 0);

  printf("%s: %d\n", print_vector(num, 0, 1000).c_str(), num.size());
  // statistical assertion testing here
  //assert(1==2);
}



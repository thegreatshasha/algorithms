# include <iostream>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

using namespace std;

int divider(unsigned long long n, unsigned long long a) {
  unsigned long long result = 9223372036854775807LL;
  result = n % a == 0 ? n/a : n/a + 1;
  return result;
}

int main() {
  unsigned long long m = 9223372036854775807LL;
  unsigned long long n = 9223372036854775807LL;
  unsigned long long a = 9223372036854775807LL;
  unsigned long long rez = 9223372036854775807LL;

  cin >> n >> m >> a;
  cout << divider(n, a) << endl;
  cout << divider(m, a) << endl;
  rez =  divider(n, a) * 100;
  cout << rez << endl;
}



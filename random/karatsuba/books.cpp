# include <iostream>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

using namespace std;

int print_array(int arr[], int m) {

  for (int i = 0; i < m; i++) {
    cout << arr[i] << endl;
  }
}

int main() {
  int books, ttime;
  cin >> books >> ttime;
  
  int time_arr[books];
  
  int pointer1 = 0, pointer2 = 0, tclock = 0, max_books_read = 0, pre_books_read = 0, books_read = 0, prevpointer = 0, prevtclock = 0;
  int exitflag = 0;

  for(int i=0; i< books; i++) {
    cin >> time_arr[i];
  }

  for(int pointer1 = 0; pointer1 < books && !exitflag; pointer1++) {
    // Precondition
    pre_books_read = books_read;
    books_read = 0;
    tclock = 0, pointer2 = pointer1;
    
    
    // Use preknowledge to reduce the number of calculations
    if(pointer1 && (pointer1 - 1 < prevpointer)) {
      int subt = pointer1 - 1;
      int alttclock = prevtclock/* - time_arr[subt]*/;
      int time_already = alttclock - time_arr[subt] > 0 ? alttclock - time_arr[subt] : 0;
      
      /*printf("(knowledge: %d=>%d ---- %d=>%d, books_read: %d, time_spent: %d)\n", time_arr[subt], subt, time_arr[prevpointer], prevpointer, pre_books_read, alttclock);
      printf("starting_from: %d=>%d --- ?\n", time_arr[pointer1], pointer1);
      printf("now: %d=>%d --- ?\n", time_arr[prevpointer+1], prevpointer+1);*/
      
      // ab karo chudaap
      tclock = time_already;
      pointer2 = prevpointer + 1;
      /*int diff = prevpointer - pointer1>0?prevpointer - pointer1:0;
      printf("%d - %d = %d\n", prevpointer, pointer1, diff);
      books_read = diff + 1;
      */
      books_read = pre_books_read - 1 > 0 ? pre_books_read - 1 : 0;
    }

    // Precondition
    /*printf("---> from %d=>%d. b_read_initially: %d, t_initial: %d\n", time_arr[pointer2], pointer2, books_read, tclock);*/

    
    while(tclock <= ttime && pointer2 < books) {
      
      // If time permits, read one more book
      /*cout << " pending: " << ttime - tclock << " : " << time_arr[pointer2] << endl;*/
      if( ttime -  tclock >= time_arr[pointer2]) {
        books_read ++;
        prevpointer = pointer2;
      }
        
      // All increment post loop
      prevtclock = tclock;
        
      tclock += time_arr[pointer2];
      
      // Store the values in the previous variables
      pointer2 ++;
      
      // Exit if we have reached the end
      if(pointer2 >= books) {
        exitflag = 1;
      }
    }
    
    /*printf("---> till %d=>%d\n", time_arr[prevpointer], prevpointer);;

    printf("b_read finally: %d. m_books_read: %d\n\n", books_read, max_books_read);*/
    
    if (books_read > max_books_read) {
      max_books_read = books_read;
    }

  }

  cout << max_books_read;
}



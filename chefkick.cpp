#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

// Define it above so i don't have to write a prototype
void input(int &n, int &m, int &k) {
	//cout << "Enter n, m, k" << endl;
	cin >> n>> m >> k;

	//int colors = [][];
	//cout << "Enter n, m, k" << endl;
}

void input(int colors[n], int profit[n][m], int loss[n][m], m, n) {
	// Initial colors of cells
  	for(int i=0; i<n; i++) {
  		cin >> colors[i];
  	}

  	for(int i=0; i<n; i++) {
  		cout << colors[i] << endl;
  	}

  	//
    for(int i=0; i<n; i++) {
    	for(int j=0; j<m; j++) {
    		cin >> profit[i][j];	
    	}
    }

    cout << "Profits are" << endl;
    for(int i=0; i<n; i++) {
    	for(int j=0; j<m; j++) {
    		cout << profit[i][j] ;	
    	}

    	cout<<endl;
    }
	

    for(int i=0; i<n; i++) {
    	for(int j=0; j<m; j++) {
    		cin >> loss[i][j];	
    	}
    }

    cout << "Losses are" << endl;

    for(int i=0; i<n; i++) {
    	for(int j=0; j<m; j++) {
    		cout << loss[i][j] ;
    	}

    	cout << endl;
    }
}

int main() {
	int n, m, k;

	input(n, m, k);

	int colors[n];
	int profit[n][m];
	int loss[n][m];

	input(colors, profit, loss, m, n);



	//cout << n << m << k << endl;
}

// Milestones: Basic input and displaying all the variables
// Matrices
// Calculations
// Displaying results


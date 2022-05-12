#include "print.h"

void print_func(vector<vector<string>> &array,int &row,int &col){
  cout << "\t|";
  for(int i = 0;i<col;i++){
    cout << char(i+'A');
    cout << "\t|";
  }
  cout<<"\n";

  for(int i = 0;i<row;i++){
    for(int j = 0;j<col;j++){
      if(j == 0) {
        cout << i + 1<< "\t|" ;
      }
      cout << array[i][j] << "\t|";
    }
    cout << endl;
  }
}
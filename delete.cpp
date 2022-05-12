#include "delete.h"

void delete_func(vector<vector<string>> &array,int &row,int &col,vector<string> &command_array){
  if(command_array[1][0] >= 'A' and command_array[1][0] <= 'Z'){
    if(col == 1){
      cout << "You cannot delete single column\n\n";
      return;
    }
    if(command_array[1][0]-65+1 > col){
      cout << "This column does not exist\n\n";
      return;
    }

    for(int i = 0;i<row;i++){
      array[i].erase(array[i].begin()+command_array[1][0]-65);
    }
  }
  else if(command_array[1][0]>= '0' and command_array[1][0]<= '9'){
    if(row == 1){
      cout << "You cannot delete single row\n\n";
      return;
    }
    if(stoi(command_array[1]) > row){
      cout<< "This row does not exist\n\n";
      return;
    }
    int akt = stoi(command_array[1]);
    array.erase(array.begin()+akt-1);
  }
}
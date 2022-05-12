#include "save.h"

void save_func(vector<vector<string>> &array,int &row,int &col,vector<string> &command_array,char &sep){
  string name = command_array[1];
  int i,j;

  if(command_array.size() >2 and command_array[2] =="-sep"){
    sep = command_array[3][0];
  }
  int element_of_row;

  ofstream saved_file;
  saved_file.open(name);

  for( i = 0 ; i < row ; i++ ){
    element_of_row = 0;
    for( j = 0 ; j < col ; j++ ){
      if ( array[i][j] != "" ){
        element_of_row++;
      }
    }

    if(element_of_row == 1){
      for (j = 0;  j< row; j++)
      {
        if(array[i][j] != "" ){
          saved_file << array[i][j];
        }
      }
      
    }
    else if(element_of_row > 1){
      element_of_row--;
      for(j = 0;j<col;j++){
        if(array[i][j] != ""){
          saved_file << array[i][j];
          if(element_of_row != 0){
            saved_file << sep;
            element_of_row--;
          }
        }
      }
    }
    if(i < row-1){
      saved_file << "\n";
    }
  }



  saved_file.close();
}
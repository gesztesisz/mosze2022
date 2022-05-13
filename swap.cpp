#include "swap.h"
void swap_func(vector<vector<string>> &array,int &row,int &col, vector<string> &command_array){
  int x1,x2;
  int y1,y2;

  if(command_array[1][0] <'A' or command_array[1][0] >'Z' or command_array[2][0] <'A' or command_array[2][0] >'Z'){
    cout << "This cell doens't exist\n";
    return;
  }
  
  x1 = stoi(command_array[1].substr(1,command_array[1].length()-1))-1;
  x2 = stoi(command_array[2].substr(1,command_array[2].length()-1))-1;

  if(x1>=row or x2>=row){
    cout << "This index doesn't exist";
    return;
  }

  y1 = command_array[1][0]-'A';
  y2 = command_array[2][0]-'A';


  if(y1 >= col or y2 >= col){
    cout << "This index doesn't exist";
    return;
  }

  string temp; 
  temp = array[x1][y1];
  array[x1][y1] = array[x2][y2];
  array[x2][y2] = temp;

}
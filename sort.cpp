#include "sort.h"

bool is_digit(const string str){
  if(str == "")
    return false;
  for(unsigned int i = 0;i<str.length();i++){
    if( (str[i] < '0' or str[i] >'9') and str[i] != '.')
      return false;
  }
  return true;
}

int len(const string str){
  int leng = 0;
  if(str == "")
    return leng;
  for(unsigned int i = 0;i<str.length();i++){
    if(str[i] == '.')
      return leng;
    leng++;
  }
  
  return leng;
}

void swapping_col(vector<vector<string>> &array,int j){
  vector<string> temp;
  temp = array[j];
  array[j] = array[j+1];
  array[j+1] = temp;
  temp.clear();
}
void swapping_row(vector<vector<string>> &array,int j,int row){
  string temp;
  for(int i = 0;i<row;i++){
    temp = array[i][j];
    array[i][j] = array[i][j+1];
    array[i][j+1] = temp;
  }
}

void sort_func(vector<vector<string>> &array, int &row, int &col, vector<string> &command_array){
  
  //bool is_asc = true;
  bool is_row;
  int pos;

  if(command_array[2][0] >= 'A' and command_array[2][0] <= 'Z'){
    is_row = false;
    pos = command_array[2][0] -'A';
  }
  else{
    is_row = true;
    pos = stoi(command_array[2])-1;
  }
  //if(command_array.size() > 2 and command_array[3] == "desc")
    //is_asc = false;

  
  if(is_row and pos+1 > row){
    cout << "Row doen't exist\n";
    return ;
  }
  else if(!is_row and pos+1 >col){
    cout << "Column doesn't exist\n";
    return ;
  }

  string str1,str2;
  if(!is_row){
    vector<string> temp;
    for (int i = 0; i < row - 1; i++){
      for (int j = 0; j < row - i - 1; j++){
        str1 =array[j][pos];
        str2 = array[j + 1][pos];
        if (is_digit(str1) > is_digit(str2)){ // sort by str & num (str<num)
          swapping_col(array,j);
        }
        else if(is_digit(str1) == is_digit(str2) and len(str1) > len(str2)){
          swapping_col(array,j);
        }
        else if(is_digit(str1) == is_digit(str2) and len(str1) == len(str2) and str1>str2){
          swapping_col(array,j);
        }
      }
    }  
  }
  else{
    for (int i = 0; i < col - 1; i++){
      for (int j = 0; j < col - i - 1; j++){
        str1 =array[pos][j];
        str2 = array[pos][j + 1];
        if (is_digit(str1) > is_digit(str2)){ // sort by str & num (str<num)
          swapping_row(array,j,row);
        }
        else if(is_digit(str1) == is_digit(str2) and len(str1) > len(str2)){
          swapping_row(array,j,row);
        }
        else if(is_digit(str1) == is_digit(str2) and len(str1) == len(str2) and str1>str2){
          swapping_row(array,j,row);
        }
      }
    }
  }

}
#include "clear.h"
void clear_func(vector<vector<string>> &array,int &row,int &col, vector<string> &command_array){
  if(command_array.size() <2 ){
    cout << "Not enough argument\n";
    return ;
  }
  string str = command_array[1]; 
  int pos =0; // position of ':' character
  for(unsigned int i = 0;i<str.length();i++)
    if(str[i] == ':')
      pos = i;
  string str1,str2;
  str1 = str.substr(0,pos);
  str2 = str.substr(pos+1);

  int start_x,start_y,end_x,end_y;
  start_x= str1[0]-'A';
  end_x = str2[0] - 'A';
  start_y = stoi(str1.substr(1))-1;
  end_y = stoi(str2.substr(1))-1;

  
  // INDEX ELLENŐRZÉS HIÁNYZIK
  int tmp;
  if(start_x > end_x){
    tmp = start_x;
    start_x = end_x;
    end_x = tmp;
  }
  if(start_y > end_y){
    tmp = start_y;
    start_y = end_y;
    end_y = start_y;
  }
  for( int i = start_y ; i <= end_y ; i++ ){
    for( int j = start_x ; j <= end_x ; j++ ){
      array[i][j] = "";
    }
  }
}
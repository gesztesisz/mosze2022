#include "functions.h"

void split_command(vector<string> &command_array,string cmd,char &sep){
  
  vector<string> vec;

  if (cmd.substr(0,4) == "edit"){
    command_array.clear();
    string temp = "";
	  for( unsigned int i=0;i<cmd.length();++i){
		
		  if(cmd[i]==sep and command_array.size() < 2){
			  command_array.push_back(temp);
			  temp = "";
		  }
		  else{
			  temp.push_back(cmd[i]);
		  }
		
	  }
	  command_array.push_back(temp);
    
  }
  else {
    command_array.clear();
    string temp = "";
	  for(unsigned int i=0;i<cmd.length();++i){
		
		  if(cmd[i]==sep){
			  command_array.push_back(temp);
			  temp = "";
		  }
		  else{
			  temp.push_back(cmd[i]);
		  }
		
	  }
	  command_array.push_back(temp);
  }
}

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

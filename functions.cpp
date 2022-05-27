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

double sum(vector<vector<string>> array, vector<string> range){
  int x,y;
  double sum = 0.0;
  for( unsigned int i = 0 ; i < range.size() ; i ++){
    x = stoi(range[i].substr(1))-1;
    y = range[i][0] - 'A';
    sum += stof(array[x][y]);
  }

  return sum;
}
double avg(vector<vector<string>> array, vector<string> range){
  int x,y;
  double avg = 0.0;
  int db = 0;
  for( unsigned int i = 0 ; i < range.size() ; i ++){
    x = stoi(range[i].substr(1))-1;
    y = range[i][0] - 'A';
      avg += stof(array[x][y]);
      db++;
  }
  return avg/db;
}
double min(vector<vector<string>> array, vector<string> range){
  int x,y;
  x = stoi(range[0].substr(1))-1;
  y = range[0][0] - 'A';
  double min = stof(array[x][y]);
  for( unsigned int i = 0 ; i < range.size() ; i ++){
    x = stoi(range[i].substr(1))-1;
    y = range[i][0] - 'A';
    if ( stof(array[x][y]) < min )
      min = stof(array[x][y]);
  }
  return min;
}
double max(vector<vector<string>> array, vector<string> range){
  int x,y;
  x = stoi(range[0].substr(1))-1;
  y = range[0][0] - 'A';
  double max= stof(array[x][y]);

  for( unsigned int i = 0 ; i < range.size() ; i ++){
    x = stoi(range[i].substr(1))-1;
    y = range[i][0] - 'A';
    if ( stof(array[x][y])> max )
      max = stof(array[x][y]);
  }
  return max;
}
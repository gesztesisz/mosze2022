#include "split.h"



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


#include "split.h"

void split_command(vector<string> &command_array,string cmd){

  if (cmd.substr(0,4) == "edit"){
    command_array.clear();
    string temp = "";
	  for(decltype(cmd.length()) i=0;i<cmd.length();++i){

		  if(cmd[i]==' ' and command_array.size() < 2){
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
	  for(decltype(cmd.length()) i=0;i<cmd.length();++i){

		  if(cmd[i]==' '){
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
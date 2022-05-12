#include "print.h"
#include "split.h"
#include "edit.h"
#include "add.h"
#include "delete.h"
#include "insert.h"
#include "save.h"
#include "cla.h"

int main(int argc,char* argv[]) {
  vector<vector<std::string>> array = {{""}};
  int row = 1,col = 1;
  vector<string> command_array;
  string cmd;

  if(argc > 1)
   cla_func(array,row,col,argc,argv);
  char sep = ';';
  while(1){
    row = array.size(); 
    col = array[0].size();
    print_func(array,row,col);

    
    
    cout <<"command: ";
    getline(cin,cmd);
    split_command(command_array,cmd,sep);

    if(command_array[0] == "edit")
      edit_func(array,command_array);
    else if(command_array[0] == "add")
      add_func(array,row,col,command_array);
    else if(command_array[0] == "delete")
      delete_func(array,row,col,command_array);
    else if(command_array[0] == "insert")
      insert_func(array,row,col,command_array);
    else if(command_array[0] == "save")
      save_func(array,row,col,command_array,sep);
    
    else if(command_array[0] == "exit") 
      break;
    else 
      cout<< "Wrong input\n\n";
  }
  
  return 0;
} 
#include "class.h"

int main(int argc,char* argv[]) {
  vector<vector<std::string>> array = {{""}};
  
  vector<string> command_array;
  string cmd;
  table *t = new table;
  t->setName("table1");
  
  if(argc > 1)
   t->cla_func(argc,argv);
  
  while(1){
    t->setRow();
    t->setCol();
    t->print_func();

    char sep = ' ';
    
    cout <<"command: ";
    getline(cin,cmd);
    cout << "\n";
    split_command(command_array,cmd,sep);
    
    if(command_array[0] == "edit")
      t->edit_func(command_array);
    else if(command_array[0] == "add")
      t->add_func(command_array);
    else if(command_array[0] == "delete")
      t->delete_func(command_array);
    else if(command_array[0] == "insert")
      t->insert_func(command_array);
    else if(command_array[0] == "save")
      t->save_func(command_array,sep);
    else if(command_array[0] == "sort")  
      t->sort_func(command_array);
    else if(command_array[0] == "swap")
      t->swap_func(command_array);
    else if(command_array[0] == "align")
      t->align_func(command_array);
    else if(command_array[0] == "clear")
      t->clear_func(command_array);
    else if(command_array[0] == "exit") 
      break;
    else 
      cout<< "Wrong input\n\n";
  }
  
  return 0;
} 
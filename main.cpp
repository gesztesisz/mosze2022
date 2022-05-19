#include "class.h"
#include "storage.h"

int main(int argc,char* argv[]) {
  vector<vector<std::string>> array = {{""}};
  
  vector<string> command_array;
  string cmd;
  vector<table*> tables;
  tables.push_back(new table);
  tables[0]->setName("table1");
  
  if(argc > 1)
   tables[0]->cla_func(argc,argv);
      int active = 0;
  while(1){


    tables[active]->setRow();
    tables[active]->setCol();
    tables[active]->print_func();
    print_table(tables,active);

    char sep = ' ';
    
    cout <<"command: ";
    getline(cin,cmd);
    cout << "\n";
    split_command(command_array,cmd,sep);
    
    if(command_array[0] == "edit")
      tables[active]->edit_func(command_array);
    else if(command_array[0] == "add")
      tables[active]->add_func(command_array);
    else if(command_array[0] == "delete")
      tables[active]->delete_func(command_array);
    else if(command_array[0] == "insert")
      tables[active]->insert_func(command_array);
    else if(command_array[0] == "save")
      tables[active]->save_func(command_array,sep);
    else if(command_array[0] == "sort")  
      tables[active]->sort_func(command_array);
    else if(command_array[0] == "swap")
      tables[active]->swap_func(command_array);
    else if(command_array[0] == "align")
      tables[active]->align_func(command_array);
    else if(command_array[0] == "clear")
      tables[active]->clear_func(command_array);
    else if(command_array[0] == "new" and command_array[1] == "sheet")
      create_table(tables,command_array,active);
    else if(command_array[0] == "switch")
      switch_func(tables,command_array,active);
    else if(command_array[0] == "rename")
      rename_func(tables,command_array);
    else if(command_array[0] == "close"){
      close_func(tables,command_array);
      if(tables.size() == 0)
        break;
    }
    else if(command_array[0] == "exit") 
      for(unsigned int i = 0;i<tables.size())
        delete tables[i];
      tables.clear();
      break;
    else 
      cout<< "Wrong input\n\n";
  }
  
  return 0;
} 
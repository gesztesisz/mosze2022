#include "print.h"
#include "split.h"

int main() {
  vector<vector<std::string>> array = {{""}};
  int row = 1,col = 1;
  vector<string> command_array;
  string cmd;

  while(1){
    row = array.size(); 
    col = array[0].size();
    print_func(array,row,col);
    
    cout <<"command: ";
    getline(cin,cmd);
    split_command(command_array,cmd);

    for(decltype(command_array.size()) i = 0;i<command_array.size();i++){
      cout << command_array[i] << "\n";
    }
  }
  
  return 0;
} 
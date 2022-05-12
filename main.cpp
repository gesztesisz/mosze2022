#include "print.h"


int main() {
  vector<vector<std::string>> array = {{""}};
  int row = array.size(); 
  int col = array[0].size();

  print_func(array,row,col);
  
  return 0;
} 
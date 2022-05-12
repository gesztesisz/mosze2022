#include"edit.h"

void edit_func(vector<vector<string>> &array,vector<string> &command_array){
  if(command_array.size() < 3){
    cout << "Not enough commands\n\n";
    return;
  }

  string pos = command_array[1];

  int y_pos = pos[0]-'A';
  int x_pos = stoi(pos.substr(1,pos.length()-1))-1;

  array[x_pos][y_pos] = command_array[2];
}

#include "add.h"

void add_func(vector<vector<string>> &array,int &row,int &col,vector<string> &command_array){

  int pcs = stoi(command_array[1]);
  if(col+pcs > 26){
    cout <<"Limit of columns is 26\n\n";
    return;
  }
  if(command_array[2] == "rows"){

    vector<string> temp;
    for(int j = 0;j<pcs;j++){  
      for(int i = 0;i<col;i++){
        temp.push_back("");
      }
      array.push_back(temp);
      temp.clear();
    }
  }else if(command_array[2] == "cols"){
    for(int j = 0;j<pcs;j++){
      for(int i = 0;i<row;i++){
        array[i].push_back("");
      }
    }

  }else{
    cout << "Wrong add command\n\n";
    return;
  }

}
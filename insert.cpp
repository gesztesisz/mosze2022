#include "insert.h"

void insert_func(vector<vector<string>> &array,int &row,int &col,vector<string> &command_array){
  int pcs = stoi(command_array[1]);
  int pos;
  vector<string> temp;

  if (command_array[2]=="rows" and (command_array[4][0] >= 'A' and command_array[4][0]<= 'Z')){
    cout << "Error! You want to edit row with column\n"<<endl;
    return;
  }
  else if(command_array[2]== "cols" and (command_array[4][0] >= '0' and command_array[4][0] <= '9')){
    cout << "Error! You want to edit column with row\n"<<endl;
    return;
  }

  if((command_array[4][0]-'A'+1 > col) and (command_array[2]== "cols")){
    cout << "This column does not exist\n"<<endl;
    return;
  } 
  /*
  if((stoi(command_array[4]) - 2 > row) and (command_array[2]== "rows")){
    cout << "This column does not exist\n"<<endl;
    return;
  }
  */

  for(int k = 0;k<pcs;k++){
    if(command_array[2] == "cols"){
        pos = command_array[4][0]-'A';
        for(int i = 0;i<row;i++){
            if(command_array[3] == "before"){
                array[i].insert(array[i].begin()+pos, "");
            }
            else if(command_array[3] == "after"){
                array[i].insert(array[i].begin()+pos+1, "");
            }
        }
    }
    else if(command_array[2] == "rows"){
        pos = stoi(command_array[4])-1;
        for(int i = 0;i<col;i++){
            temp.push_back("");
        }

        if(command_array[3] == "before"){
            array.insert(array.begin()+pos,temp);
            temp.clear();
        }
        else if(command_array[3] == "after"){
            array.insert(array.begin() + pos+1 , temp);
            temp.clear();
        }
    }
  }  
}
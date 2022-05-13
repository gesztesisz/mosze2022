#include "cla.h"
#include "add.h"
#include "split.h"

void cla_func(vector<vector<string>> &array,int &row,int &col,int &argc,char *argv[]){
   
    string text; 
    vector<string> lines,vec;
    ifstream input_csv(argv[1]);
    char sep = ';';
    if(argc>2 ){
      sep = argv[3][0];
    }
    
    vector<string> temp_command = {"","",""};
    

    int max_row = 0;
    int sep_count;
    while(getline(input_csv,text)){
      lines.push_back(text);
    }
    input_csv.close();
    for(unsigned int i = 0;i<lines.size();i++){
      sep_count = 0;
      for(unsigned int j = 0;j<lines[i].length();j++){
        if(lines[i][j] == sep){
          sep_count ++;
        }
      }
      if(sep_count+1 > max_row){
        max_row = sep_count+1;
      }
    }
    
    row = array.size(); 
    col = array[0].size();
    temp_command[2] = "rows";
    temp_command[1] = to_string(lines.size()-1);
    add_func(array,row,col,temp_command);
    
    row = array.size(); 
    col = array[0].size();
    temp_command[2] = "cols";
    temp_command[1] = to_string(max_row-1);
    add_func(array,row,col,temp_command);
    
    row = array.size();
    col = array[0].size();
    string temp;
    for(int i = 0;i<row;i++){
      temp = lines[i];
      split_command(temp_command,temp,sep);
      vec = temp_command;
      for(unsigned int j = 0;j<vec.size();j++){
        if(vec[j] != ""){
          array[i][j] = vec[j];
        }
      }
    }
  
}
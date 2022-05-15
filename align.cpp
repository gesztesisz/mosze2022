#include "align.h"

void align_func(vector<vector<string>> &array,int &row,int &col,vector<string> &command_array,vector<string> &align_right){
  bool more = false;
  bool right = false; //default: left align
  for(unsigned int i = 0;i<command_array[1].length();i++)
    if(command_array[1][i] == ':'){
      more = true;
      break;
    }
  if(command_array.size()<3){
    cout << "Not enough argument\n";
    return;
  }
  if(command_array[2] == "right")
    right = true;
  
  string str = command_array[1];
  string temp;
  int x,y;
  
  if(!more){
    x = str[0]-'A';
    y = stoi(str.substr(1));
  /*
    if(x >=col or y >= row){
      cout << "Too big index\n";
      return;
    }
    else{*/
      temp = char(x+'A');
      temp += to_string(y);
    //}
    
    if(find(align_right.begin(),align_right.end(),temp) == align_right.end() and right)
      align_right.push_back(temp);
    //else if(find(align_right.begin(),align_right.end(),temp) == align_right.end() and !right)
      
    else if(find(align_right.begin(),align_right.end(),temp) != align_right.end() and right)
      cout << "The cell is already aligned\n";
    else if(find(align_right.begin(),align_right.end(),temp) != align_right.end() and !right)
      align_right.erase(std::remove(align_right.begin(), align_right.end(), temp), align_right.end());
    
  }
  else{
    
    int pos =0; // position of ':' character
    for(unsigned int i = 0;i<str.length();i++)
      if(str[i] == ':')
        pos = i;
    string str1,str2;
    str1 = str.substr(0,pos);
    str2 = str.substr(pos+1);

    int start_x,start_y,end_x,end_y;
    start_x= str1[0]-'A';
    end_x = str2[0] - 'A';
    start_y = stoi(str1.substr(1));
    end_y = stoi(str2.substr(1));


    int tmp;
    if(start_x > end_x){
      tmp = start_x;
      start_x = end_x;
      end_x = tmp;
    }
    if(start_y > end_y){
      tmp = start_y;
      start_y = end_y;
      end_y = start_y;
    }/*
    if(start_x >= col or end_x >= col){
      cout << "Out of range\n";
      return;
    }
    else if(start_y >= row or end_y >= row){
      cout << "Out of range\n";
      return;
    }
    */
    string index;
    for(int i = start_x;i<=end_x;i++){
      for(int j = start_y ;j<= end_y;j++){
        index = "";
        index += char(i+'A');
        index += to_string(j);
        if(find(align_right.begin(),align_right.end(),index) == align_right.end() and right)
          align_right.push_back(index);
        else if(find(align_right.begin(),align_right.end(),index) != align_right.end() and !right)
          align_right.erase(std::remove(align_right.begin(), align_right.end(), index), align_right.end());
      }
    }
  }  

}
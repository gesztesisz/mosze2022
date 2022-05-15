#include "print.h"
#include "align.h"

void print_func(vector<vector<string>> &array,int &row,int &col,vector<string> &align_right){
  string ind = "";
 int width[col + 1]; //First element is full width 
  unsigned int temp = 0;
  int i,j;
  string str = "";
  for (i = 0;i<col;i++){
    width[i] = 0;
  }

  for(i = 0;i<col;i++){
    for(j = 0;j<row;j++){
     if(array[j][i].length() > temp){
       temp = array[j][i].length();
     }
    }
    width[i+1] = temp;
    temp = 0;
  }
  width[0] = trunc(log10(row)) + 1; // 1 = 1, 10 = 2, 100 = 3

  for(i = 0;i<col+1;i++){
    if(width[i] == 0){
      str+= "-";
      continue;
    }
    for(j = 0;j<width[i];j++){
      str += "-";
    }
  }
  for(i = 0;i<col+1;i++){
    str+= "-";
  }


  for(i = 0;i<width[0];i++){
    cout << " ";
  }
  cout << "|";
  for(i = 0;i<col;i++){
    cout <<char(i+'A');
    for(j = 0;j<width[i+1]-1;j++){
      cout << " ";
    }
    cout << "|";
  }

  cout <<"\n"<<str<<"\n";
  
  for(i = 0;i<row;i++){
    cout << i+1;
    for(int k = trunc(log10(i+1)) + 1;k<width[0];k++){
      cout << " ";
    }
    cout << "|";
    for(j = 0;j<col;j++){
      ind = char(j+'A');
      ind += to_string(i+1);
      if(width[j+1] == 0){
        cout <<" |";
        continue;  
      }
      if(find(align_right.begin(),align_right.end(),ind) == align_right.end()){
        cout << array[i][j];
        for(int l = array[i][j].length();l<width[j+1];l++){
          cout << " ";
        }
      }
      else{
        for(int l = array[i][j].length();l<width[j+1];l++){
          cout << " ";
        }
        cout << array[i][j];
      }
      
    

      cout << "|";
    }
    cout <<"\n"<< str<<"\n";
  }

}


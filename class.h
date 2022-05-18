#include "headers.h"
#include "functions.h"

/**
 * @brief TEST
 * 
 */

class table{
private:
  string name ;
  vector<vector<string>> array = {{""}};
  int row,col;
  vector<string> align_right;
public:
  table(){}

  vector<vector<string>> getArray() { return array; }
  int getRow() { 
    row = array.size();    
    return row; 
  }
  int getCol() { 
    col = array[0].size();
    return col; 
  }
  string getName(){return name;}

  void setRow();
  void setCol(); 
  void setName(string name);

  void add_func(vector<string> &command_array);

  vector<string> align(string str);
  void align_func(vector<string> &command_array);
  
  void cla_func(int &argc, char *argv[]);
  void clear_func(vector<string> &command_array);
  void delete_func(vector<string> &command_array);
  void edit_func(vector<string> &command_array);
  void insert_func(vector<string> &command_array);
  void print_func();
  void save_func(vector<string> &command_array,char &sep);
  void sort_func(vector<string> &command_array);
  void swap_func(vector<string> &command_array);
};
#include "class.h"

void table::setName(string name){
  this->name = name;
}

void table::setRow(){
  row = array.size();
}
void table::setCol(){
  col = array[0].size();
}

void table::add_func(vector<string> &command_array){
  row = getRow();
  col = getCol();
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

vector<string> table::align(string str){
  vector<string> ret;
  int pos = 0;
  bool more = false;
  for(unsigned int i = 0;i<str.length();i++)
    if(str[i] == ':'){
      more = true;
      pos = i;
      break;
    }
  int x,y;
  
  string temp;
  if(!more){
    x = str[0]-'A';
    y = stoi(str.substr(1));

    temp = char(x+'A');
    temp += to_string(y);

    ret.push_back(temp);    
  }
  else{
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
    }
    string index;
    for(int i = start_x;i<=end_x;i++){
      for(int j = start_y ;j<= end_y;j++){
        index = "";
        index += char(i+'A');
        index += to_string(j);
        ret.push_back(index);
      }
    }
  }
  return ret;
}

void table::align_func(vector<string> &command_array){
  bool right = false; //default: left align

  if(command_array.size()<3){
    cout << "Not enough argument\n";
    return;
  }
  if(command_array[2] == "right")
    right = true;
  
  vector<string> v = align(command_array[1]);
  for(unsigned int i = 0;i<v.size();i++)
    if(find(align_right.begin(),align_right.end(),v[i]) == align_right.end() and right)
      align_right.push_back(v[i]);
    //else if(find(align_right.begin(),align_right.end(),temp) == align_right.end() and !right)
    else if(find(align_right.begin(),align_right.end(),v[i]) != align_right.end() and right)
      cout << "The cell is already aligned\n";
    else if(find(align_right.begin(),align_right.end(),v[i]) != align_right.end() and !right)
      align_right.erase(std::remove(align_right.begin(), align_right.end(), v[i]), align_right.end());
}

void table::cla_func(int &argc, char *argv[]){

    setName(argv[1]);
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
    add_func(temp_command);
    
    row = array.size(); 
    col = array[0].size();
    temp_command[2] = "cols";
    temp_command[1] = to_string(max_row-1);
    add_func(temp_command);
    
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

void table::clear_func(vector<string> &command_array){
  if(command_array.size() <2 ){
    cout << "Not enough argument\n";
    return ;
  }
  string str = command_array[1]; 
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
  start_y = stoi(str1.substr(1))-1;
  end_y = stoi(str2.substr(1))-1;

  
  // INDEX ELLENŐRZÉS HIÁNYZIK
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
  }
  for( int i = start_y ; i <= end_y ; i++ ){
    for( int j = start_x ; j <= end_x ; j++ ){
      array[i][j] = "";
    }
  }
}

void table::delete_func(vector<string> &command_array){
  if(command_array[1][0] >= 'A' and command_array[1][0] <= 'Z'){
    if(col == 1){
      cout << "You cannot delete single column\n\n";
      return;
    }
    if(command_array[1][0]-65+1 > col){
      cout << "This column does not exist\n\n";
      return;
    }

    for(int i = 0;i<row;i++){
      array[i].erase(array[i].begin()+command_array[1][0]-65);
    }
  }
  else if(command_array[1][0]>= '0' and command_array[1][0]<= '9'){
    if(row == 1){
      cout << "You cannot delete single row\n\n";
      return;
    }
    if(stoi(command_array[1]) > row){
      cout<< "This row does not exist\n\n";
      return;
    }
    int akt = stoi(command_array[1]);
    array.erase(array.begin()+akt-1);
  }
}

void table::edit_func(vector<string> &command_array){
 if(command_array.size() < 3){
    cout << "Not enough commands\n\n";
    return;
  }

  string pos = command_array[1];

  int y_pos = pos[0]-'A';
  int x_pos = stoi(pos.substr(1,pos.length()-1))-1;

  array[x_pos][y_pos] = command_array[2];
}

void table::insert_func(vector<string> &command_array){
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

void table::print_func(){
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

void table::save_func(vector<string> &command_array,char &sep){
  string name = command_array[1];
  int i,j;
  sep = ';';
  if(command_array.size() >2 and command_array[2] =="-sep"){
    sep = command_array[3][0];
  }
  int element_of_row;
  ofstream saved_file;
  saved_file.open(name);
  for( i = 0 ; i < row ; i++ ){
    element_of_row = 0;
    for( j = 0 ; j < col ; j++ ){
      if ( array[i][j] != "" ){
        element_of_row++;
      }
    }
    if(element_of_row == 1){
      for (j = 0;  j< row; j++)
      {
        if(array[i][j] != "" ){
          saved_file << array[i][j];
        }
      }
    }
    else if(element_of_row > 1){
      element_of_row--;
      for(j = 0;j<col;j++){
        if(array[i][j] != ""){
          saved_file << array[i][j];
          if(element_of_row != 0){
            saved_file << sep;
            element_of_row--;
          }
        }
      }
    }
    if(i < row-1){
      saved_file << "\n";
    }
  }
  saved_file.close();
}

void table::sort_func(vector<string> &command_array){
  bool is_asc = true;
  bool is_row;
  int pos;
  if(command_array.size()>3 and command_array[3] == "desc")
    is_asc = false;
  if(command_array[2][0] >= 'A' and command_array[2][0] <= 'Z'){
    is_row = false;
    pos = command_array[2][0] -'A';
  }
  else{
    is_row = true;
    pos = stoi(command_array[2])-1;
  }
  //if(command_array.size() > 2 and command_array[3] == "desc")
    //is_asc = false;
  if(is_row and pos+1 > row){
    cout << "Row doen't exist\n";
    return ;
  }
  else if(!is_row and pos+1 >col){
    cout << "Column doesn't exist\n";
    return ;
  }
  string str1,str2;
  if(!is_row){
    vector<string> temp;
    for (int i = 0; i < row - 1; i++){
      for (int j = 0; j < row - i - 1; j++){
        str1 =array[j][pos];
        str2 = array[j + 1][pos];
        if (is_digit(str1) > is_digit(str2) and is_asc){ // sort by str & num (str<num)
          swapping_col(array,j);
        }
        else if(is_digit(str1) < is_digit(str2) and !is_asc){ // sort by str & num (str<num)
          swapping_col(array,j);
        }
        if(is_digit(str1) == is_digit(str2) and len(str1) > len(str2) and is_asc ){
          swapping_col(array,j);
        }
        else if(is_digit(str1) == is_digit(str2) and len(str1) < len(str2) and !is_asc){
          swapping_col(array,j);
        }
        if(is_digit(str1) == is_digit(str2) and len(str1) == len(str2) and str1>str2 and is_asc){
          swapping_col(array,j);
        }
        else if(is_digit(str1) == is_digit(str2) and len(str1) == len(str2) and str1 < str2 and !is_asc){
          swapping_col(array,j);
        }
      }
    }  
  }
  else{
    for (int i = 0; i < col - 1; i++){
      for (int j = 0; j < col - i - 1; j++){
        str1 =array[pos][j];
        str2 = array[pos][j + 1];
        if (is_digit(str1) > is_digit(str2) and is_asc){ // sort by str & num (str<num)
          swapping_row(array,j,row);
        }
        else if(is_digit(str1) < is_digit(str2) and !is_asc){
          swapping_row(array,j,row);
        }
        if(is_digit(str1) == is_digit(str2) and len(str1) > len(str2) and is_asc){
          swapping_row(array,j,row);
        }
        else if(is_digit(str1) == is_digit(str2) and len(str1) < len(str2) and !is_asc){
          swapping_row(array,j,row);
        }
        if(is_digit(str1) == is_digit(str2) and len(str1) == len(str2) and str1>str2){
          swapping_row(array,j,row);
        }
        else if(is_digit(str1) == is_digit(str2) and len(str1) == len(str2) and str1 < str2 and !is_asc){
          swapping_row(array,j,row);
        }
      }
    }
  }
}

void table::swap_func(vector<string> &command_array){
    int x1,x2;
  int y1,y2;

  if(command_array[1][0] <'A' or command_array[1][0] >'Z' or command_array[2][0] <'A' or command_array[2][0] >'Z'){
    cout << "This cell doens't exist\n";
    return;
  }
  
  x1 = stoi(command_array[1].substr(1,command_array[1].length()-1))-1;
  x2 = stoi(command_array[2].substr(1,command_array[2].length()-1))-1;

  if(x1>=row or x2>=row){
    cout << "This index doesn't exist";
    return;
  }

  y1 = command_array[1][0]-'A';
  y2 = command_array[2][0]-'A';


  if(y1 >= col or y2 >= col){
    cout << "This index doesn't exist";
    return;
  }

  string temp; 
  temp = array[x1][y1];
  array[x1][y1] = array[x2][y2];
  array[x2][y2] = temp;

}


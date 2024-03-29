#include "storage.h"

//!  Print function. 
/*!
    This print all of table to stdout.
*/
void print_table(vector<table*> tables,int &active){
    for(unsigned int  i = 0;i<tables.size();i++){
        cout << i  << ": "<< tables[i]->getName();
        if(unsigned(active) == i)
            cout << "*";
        cout << "  ";
    }
    cout << "\n";
}

//!  Create function. 
/*!
    Create a new table and set active with given name.
*/
void create_table(vector<table*> &tables,vector<string> &command_array,int &active){
    tables.push_back(new table);
    active = tables.size()-1;
    tables[active]->setName(command_array[2]);
}

//!  Switch function. 
/*!
    It changes active table.
*/
void switch_func(vector<table*> &tables,vector<string> &command_array,int &active){
    if(unsigned(stoi(command_array[1])) > tables.size()-1){
        cout <<"Out of range\n";
        return;
    }
    active  = stoi(command_array[1]);
}

//!  Rename function. 
/*!
    It sets a new name to table
*/
void rename_func(vector<table*> &tables,vector<string> &command_array){
    if(command_array.size() < 3){
        cout << "Not enough argument\n";
        return;
    }
    
    tables[stoi(command_array[1])]->setName(command_array[2]);
}

//!  Close function. 
/*!
    It close a table and free up memory.
*/
void close_func(vector<table*> &tables,vector<string> &command_array,int &active){
    int ind = stoi(command_array[1]);
    if(active == ind){
        cout << "Can't close active table. Use 'switch <index>' to change active table.\n";
        return;
    }
    delete tables[ind];
    tables.erase(tables.begin() + ind);

}
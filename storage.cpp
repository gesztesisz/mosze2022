#include "storage.h"

void print_table(vector<table*> tables,int &active){
    for(unsigned int  i = 0;i<tables.size();i++){
        cout << i  << ": "<< tables[i]->getName();
        if(active == i)
            cout << "*";
        cout << "  ";
    }
    cout << "\n";
}

void create_table(vector<table*> &tables,vector<string> &command_array,int &active){
    tables.push_back(new table);
    active = tables.size()-1;
    tables[active]->setName(command_array[2]);
}
void switch_func(vector<table*> &tables,vector<string> &command_array,int &active){
    if(stoi(command_array[1]) > tables.size()-1){
        cout <<"Out of range\n";
        return;
    }
    active  = stoi(command_array[1]);
}
void rename_func(vector<table*> &tables,vector<string> &command_array){
    if(command_array.size() < 3){
        cout << "Not enough argument\n";
        return;
    }
    
    tables[stoi(command_array[1])]->setName(command_array[2]);
}
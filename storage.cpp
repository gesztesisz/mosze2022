#include "storage.h"

void print_table(vector<table*> tables,int &active){
    for(unsigned int  i = 0;i<tables.size();i++){
        cout << i + 1 << ": "<< tables[i]->getName();
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
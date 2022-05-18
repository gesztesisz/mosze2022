#include "headers.h"
#include "class.h"

void print_table(vector<table*> tables,int &active);
void create_table(vector<table*> &tables,vector<string> &command_array,int &active);
void switch_func(vector<table*> &tables,vector<string> &command_array,int &active);
void rename_func(vector<table*> &tables,vector<string> &command_array);
#include "headers.h"

void split_command(vector<string> &command_array,string cmd,char &sep);
bool is_digit(const string str);
int len(const string str);
void swapping_col(vector<vector<string>> &array,int j);
void swapping_row(vector<vector<string>> &array,int j,int row);

double sum(vector<vector<string>> array, vector<string> range);
double avg(vector<vector<string>> array, vector<string> range);
double min(vector<vector<string>> array, vector<string> range);
double max(vector<vector<string>> array, vector<string> range);
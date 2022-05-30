#include<gtest/gtest.h>
#include "class.h"

TEST(MulTest, align_test){
    table t;
    vector<string> v = t.align("A1:C3");
    ASSERT_EQ(9,v.size());
}


TEST(MulTest, sum_test){
    vector<vector<string>> expect = {
        {"3.000","2"},
        {"1","2"}
    };
    
    table t;
    vector<string> comm = {"add","1","rows"};
    t.add_func(comm);
    comm[2] = "cols";
    t.add_func(comm);
    comm.clear();
    
    comm = {"edit","A1","1"};
    t.edit_func(comm);
    comm = {"edit","B1","2"};
    t.edit_func(comm);
    comm = {"edit","A2","1"};
    t.edit_func(comm);
    comm = {"edit","B2","2"};
    t.edit_func(comm);
    
    comm = {"set","A1","sum(A1:B2)"};
    t.aggregate_func(comm);
    ASSERT_EQ(expect,t.getArray());
    
}

TEST(MulTest, avg_test){
    vector<vector<string>> expect = {
        {"1.500","2"},
        {"1","2"}
    };
    
    table t;
    vector<string> comm = {"add","1","rows"};
    t.add_func(comm);
    comm[2] = "cols";
    t.add_func(comm);
    comm.clear();
    
    comm = {"edit","A1","1"};
    t.edit_func(comm);
    comm = {"edit","B1","2"};
    t.edit_func(comm);
    comm = {"edit","A2","1"};
    t.edit_func(comm);
    comm = {"edit","B2","2"};
    t.edit_func(comm);
    
    comm = {"set","A1","avg(A1:B2)"};
    t.aggregate_func(comm);
    ASSERT_EQ(expect,t.getArray());
    
}

TEST(MulTest, min_test){
    vector<vector<string>> expect = {
        {"1.000","2"},
        {"1","2"}
    };
    
    table t;
    vector<string> comm = {"add","1","rows"};
    t.add_func(comm);
    comm[2] = "cols";
    t.add_func(comm);
    comm.clear();
    
    comm = {"edit","A1","1"};
    t.edit_func(comm);
    comm = {"edit","B1","2"};
    t.edit_func(comm);
    comm = {"edit","A2","1"};
    t.edit_func(comm);
    comm = {"edit","B2","2"};
    t.edit_func(comm);
    
    comm = {"set","A1","min(A1:B2)"};
    t.aggregate_func(comm);
    ASSERT_EQ(expect,t.getArray());
    
}

TEST(MulTest, max_test){
    vector<vector<string>> expect = {
        {"2.000","2"},
        {"1","2"}
    };
    
    table t;
    vector<string> comm = {"add","1","rows"};
    t.add_func(comm);
    comm[2] = "cols";
    t.add_func(comm);
    comm.clear();
    
    comm = {"edit","A1","1"};
    t.edit_func(comm);
    comm = {"edit","B1","2"};
    t.edit_func(comm);
    comm = {"edit","A2","1"};
    t.edit_func(comm);
    comm = {"edit","B2","2"};
    t.edit_func(comm);
    
    comm = {"set","A1","max(A1:B2)"};
    t.aggregate_func(comm);
    ASSERT_EQ(expect,t.getArray());
    
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
//
// Created by xiaoli he on 5/29/20.
//
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;


class Student{
    string name, id;
    int age, grade[4];
public:
    void SetALL(vector<string> input){
        name = input[0];
        age = atoi(input[1].c_str());
        id = input[2];
        grade[0] = atoi(input[3].c_str());
        grade[1] = atoi(input[4].c_str());
        grade[2] = atoi(input[5].c_str());
        grade[3] = atoi(input[6].c_str());

    };

    void get_basic(char sep){
        cout << name << sep <<  age << sep << id;
    }


    int get_average(){
        return floor((grade[0] + grade[1] + grade[2] + grade[3])/4);
    }

};

int main(){
    string input_str;
    getline(cin, input_str);
    char sep = ',';
    istringstream split(input_str);
    vector<string> tokens;
    for(string each;getline(split, each, sep); tokens.push_back(each));
//    for(int i=0; i<tokens.size(); ++i)
//        std::cout << tokens[i] << ':';
    Student xx;
    xx.SetALL(tokens);
    xx.get_basic(sep);
    cout << sep << xx.get_average() << endl;
    return 0;
}

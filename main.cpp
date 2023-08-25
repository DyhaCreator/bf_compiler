#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include "Err_list.h"
#include "token.h"
#include "lexer.h"

int main(int a, char *argv[]){
    std::ifstream inf(argv[1]);
    if(!inf.is_open()){
        Err(0);
        return 1;
    }
    std::string Code;
    std::string str;
    while(getline(inf, str)){
        Code += str;
    }
    cleaning_code(Code);
    std::cout << Code << std::endl;
    std::vector<token>tokens = lex(Code);
    return 0;
}
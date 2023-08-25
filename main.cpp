#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include "Err_list.h"
#include "token.h"
#include "lexer.h"
#include "interpreter.h"

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
    inf.close();
    cleaning_code(Code);
    //std::cout << Code << std::endl;
    std::vector<token>tokens = lex(Code);
    //for(int i = 0; i < tokens.size(); i++)std::cout << tokens[i].name << " " << tokens[i].code << std::endl;
    std::string CCode = inter(tokens);
    std::ofstream out;
    out.open("CCode.c");
    out << CCode;
    out.close();
    system("gcc CCode.c");
    system("rm CCode.c");
    return 0;
}
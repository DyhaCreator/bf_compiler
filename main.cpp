#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include "Err_list.h"
#include "lex_struct.h"
#include "token.h"
#include "lexer.h"
#include "interpreter.h"

int main(int a, char *argv[]){
    Lex lex = Lex();
    std::string str;
    std::ifstream inf(argv[1]);
    if(!inf.is_open()){
        Err(0);
        return 1;
    }
    std::ifstream inlex(argv[2]);
    if(!inlex.is_open() && argv[2]){
        Err(3);
        return 1;
    }
    if(inlex.is_open() && argv[2]){
        std::string lexicon = "";
        while(getline(inlex, str)){
            lexicon += str;
        }
        //std::cout << lexicon << std::endl;
        create_lex(lexicon, lex);
    }
    std::string Code;
    while(getline(inf, str)){
        Code += str;
    }
    inf.close();
    Code = cleaning_code(Code + " ", lex);
    //std::cout << Code << std::endl;
    std::vector<token>tokens = lexer(Code, lex);
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
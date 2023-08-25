#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "token.h"
#include "lexer.h"

int main(int a, char *argv[]){
    std::ifstream inf(argv[1]);
    if(!inf.is_open()){
        std::cout << "Err 0x00" << std::endl;
        std::cout << "when opening a file" << std::endl;
        return 1;
    }
    std::string Code;
    std::string str;
    while(getline(inf, str)){
        Code += str;
    }
    std::cout << Code << std::endl;
    return 0;
}
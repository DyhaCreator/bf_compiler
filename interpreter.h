std::string inter(std::vector<token> tokens){
    std::string CCode = "#include <stdio.h>\nint main(){char mem[65536];int p=0;";

    for(int i = 0; i < tokens.size(); i++){
        //std::cout << tokens[i].analog << " " << tokens[i].code << std::endl;
        if(tokens[i].analog == '+'){
            CCode += "mem[p]+=" + std::to_string(tokens[i].code) + ";";
        }
        else if(tokens[i].analog == '-'){
            CCode += "mem[p]-=" + std::to_string(tokens[i].code) + ";";
        }
        else if(tokens[i].analog == '.')
            CCode += "printf(\"%c\",mem[p]);";
        else if(tokens[i].analog == ',')
            CCode += "scanf(\"%c\",&mem[p]);";
        else if(tokens[i].analog == '>')
            CCode += "p+=" + std::to_string(tokens[i].code) + ";";
        else if(tokens[i].analog == '<')
            CCode += "p-=" + std::to_string(tokens[i].code) + ";";
        else if(tokens[i].analog == '[')
            CCode += "while(mem[p]>0){";
        else if(tokens[i].analog == ']')
            CCode += "}";
    }

    return CCode + "return 0;}";
}
std::string inter(std::vector<token> tokens){
    std::string CCode = "#include <stdio.h>\nint main(){char mem[65536];int p=0;";

    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i].name == "+"){
            CCode += "mem[p]+=" + std::to_string(tokens[i].code) + ";";
        }
        else if(tokens[i].name == "-"){
            CCode += "mem[p]-=" + std::to_string(tokens[i].code) + ";";
        }
        else if(tokens[i].name == ".")
            CCode += "printf(\"%c\",mem[p]);";
        else if(tokens[i].name == ",")
            CCode += "scanf(\"%c\",&mem[p]);";
        else if(tokens[i].name == ">")
            CCode += "p+=" + std::to_string(tokens[i].code) + ";";
        else if(tokens[i].name == "<")
            CCode += "p-=" + std::to_string(tokens[i].code) + ";";
        else if(tokens[i].name == "[")
            CCode += "while(mem[p]>0){";
        else if(tokens[i].name == "]")
            CCode += "}";
    }

    return CCode + "return 0;}";
}
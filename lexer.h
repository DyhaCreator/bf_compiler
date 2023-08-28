std::vector<token> lexer(std::string code, Lex lex){
    std::vector<token>tokens = std::vector<token>();
    std::string command = "";
    for(int j = 0; j < code.size(); j++){
        bool isFinded = false;
        int i = j;
        while(i < code.size()){
            command += code[i];
            if( command == lex.plus ||
                command == lex.minus ||
                command == lex.in ||
                command == lex.out ||
                command == lex.right ||
                command == lex.left ||
                command == lex.start ||
                command == lex.end){
                    
                    if(command == lex.plus){
                        if(tokens.size() > 0 && tokens[tokens.size() - 1].analog == '+'){
                            tokens[tokens.size() - 1].code ++;
                        }
                        else{
                            tokens.push_back(token(1, command, '+'));
                        }
                    }
                    else if(command == lex.minus){
                        if(tokens.size() > 0 && tokens[tokens.size() - 1].analog == '-'){
                            tokens[tokens.size() - 1].code ++;
                        }
                        else{
                            tokens.push_back(token(1, command, '-'));
                        }
                    }
                    else if(command == lex.in)
                        tokens.push_back(token(0, command, ','));
                    else if(command == lex.out)
                        tokens.push_back(token(0, command, '.'));
                    else if(command == lex.right){
                        if(tokens.size() > 0 && tokens[tokens.size() - 1].analog == '>'){
                            tokens[tokens.size() - 1].code ++;
                        }
                        else{
                            tokens.push_back(token(1, command, '>'));
                        }
                    }
                    else if(command == lex.left){
                        if(tokens.size() > 0 && tokens[tokens.size() - 1].analog == '<'){
                            tokens[tokens.size() - 1].code ++;
                        }
                        else{
                            tokens.push_back(token(1, command, '<'));
                        }
                    }
                    else if(command == lex.start)
                        tokens.push_back(token(0, command, '['));
                    else if(command == lex.end)
                        tokens.push_back(token(0, command, ']'));
                    isFinded = true;
                    break;
            }
            i++;
        }
        if(isFinded){
            j += command.size() - 1;
        }
        command = "";
    }
    std::stack<char>st;
    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i].analog == '['){
            st.push('[');
        }
        else if(tokens[i].analog == ']'){
            if(st.empty()){
                std::cout << "token " << i << std::endl;
                int size = tokens.size();
                for(int j = std::max(0, i - 100); j < std::min(i + 100, size); j++){
                    if(j == i){
                        printf("\x1B[31m]\033[0m");
                    }
                    else{
                        std::cout << tokens[j].name;
                    }
                }
                std::cout << std::endl;
                Err(1);
                break;
            }
            else{
                st.pop();
            }
        }
    }
    if(!st.empty()){
        Err(2);
    }
    return tokens;
}

std::string cleaning_code(std::string code, Lex lex){
    std::string clearCode = "", command = "";
    for(int j = 0; j < code.size() - 1; j++){
        bool isFinded = false;
        int i = j;
        for(;i < code.size(); i++){
            command += code[i];
            if( command == lex.plus ||
                command == lex.minus ||
                command == lex.in ||
                command == lex.out ||
                command == lex.right ||
                command == lex.left ||
                command == lex.start ||
                command == lex.end){
                    clearCode += command + " ";
                    isFinded = true;
                    break;
            }
        }
        if(isFinded){
            j += command.size() - 1;
        }
        command = "";
    }
    code = clearCode;
    return code;
}
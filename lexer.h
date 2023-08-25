std::vector<token> lex(std::string code){
    std::stack<char>st;
    std::vector<token>tokens = std::vector<token>();
    for(int i = 0; i < code.size(); i++){
        int num = 1;
        if(code[i] == '['){
            st.push('[');
        }
        else if(code[i] == ']'){
            if(st.empty()){
                std::cout << "symbol " << i << std::endl;
                int size = code.size();
                for(int j = std::max(0, i - 100); j < std::min(i + 100, size); j++){
                    if(j == i){
                        printf("\x1B[31m]\033[0m");
                    }
                    else{
                        std::cout << code[j];
                    }
                }
                std::cout << std::endl;
                Err(1);
            }
            else{
                st.pop();
            }
        }
        else if(code[i] == '+' || code[i] == '-'){
            for(int j = i + 1; j < code.size(); j++){
                if(code[j] != code[i]){
                    break;
                }
                num++;
                i++;
            }
        }
        else if(code[i] == '>' || code[i] == '<'){
            for(int j = i + 1; j < code.size(); j++){
                if(code[j] != code[i]){
                    break;
                }
                num++;
                i++;
            }
        }
        tokens.push_back(token(num, code[i]));
    }
    if(!st.empty()){
        Err(2);
    }
    return tokens;
}

int cleaning_code(std::string& code){
    std::string lexis = "+-.,><[]";
    for(int i = 0; i < code.size(); i++){
        if(lexis.find(code[i]) == std::string::npos){
            code.erase(code.begin() + i);
            i--;
        }
    }
    return 0;
}
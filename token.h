struct token{
    int code;
    std::string name;
    token(){}
    token(char name){
        this->name = name;
    }
    token(int code, char name){
        this->code = code;
        this->name = name;
    }
    token(std::string name){
        this->code = 0;
        this->name = name;
    }
    token(int code, std::string name){
        this->code = code;
        this->name = name;
    }
};
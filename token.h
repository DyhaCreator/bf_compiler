struct token{
    int code;
    std::string name;
    char analog;
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
    token(int code, std::string name, char analog){
        this->code = code;
        this->name = name;
        this->analog = analog;
    }
};
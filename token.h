struct token{
    int code;
    std::string name;
    token(int code, std::string name){
        this->code = code;
        this->name = name;
    }
}
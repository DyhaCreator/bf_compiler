struct Lex{
    std::string plus = "+", minus = "-", in = ",", out = ".", right = ">", left = "<", start = "[", end = "]";
    Lex(){}
    Lex(std::string plus,
        std::string minus,
        std::string in,
        std::string out,
        std::string right,
        std::string left,
        std::string start,
        std::string end){
        this->plus = plus;this->minus = minus;
        this->in = in; this->out = out;
        this->right = right; this->left = left;
        this->start = start; this->end = end;
    }
};

void create_lex(std::string lexicon, Lex& lex){
    std::string line = "";
    for(int i = 0; i < lexicon.size(); i++){
        if(lexicon[i] == ';'){
            std::string code = line.substr(line.find('"') + 1, line.rfind('"') - line.find('"') - 1);
            switch(line[0]){
                case '+':
                    lex.plus = code;
                    break;
                case '-':
                    lex.minus = code;
                    break;
                case ',':
                    lex.in = code;
                    break;
                case '.':
                    lex.out = code;
                    break;
                case '<':
                    lex.left = code;
                    break;
                case '>':
                    lex.right = code;
                    break;
                case '[':
                    lex.start = code;
                    break;
                case ']':
                    lex.end = code;
                    break;
            }
            line = "";
        }
        else{
            line += lexicon[i];
        }
    }
}
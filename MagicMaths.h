#include "headers.h"

class MagicMaths {
    private:
        std::string equation;
        NoobStack<int> nums;
        NoobStack<char> op;

        std::string convertPostFix(std::string eq);
        int assignValue(char a);

    public:

        MagicMaths();
        ~MagicMaths();

        friend std::istream& operator >> (std::istream &in, MagicMaths obj);



};


MagicMaths::MagicMaths(){

}

MagicMaths::~MagicMaths(){

}

int MagicMaths::assignValue(char a){
    switch(a):{
        case '(':
            return 0;
        case '^':
            return 1;
        case '/':
            return 2;
        case '*':
            return 3;
        case '+':
            return 4;
        case '-':
            return 5;
        case ')':
            return 6;
        default:
            return -1001001;
    }
}

std::string MagicMaths::convertPostFix(std::string eq){
    this->op.push(')');
    for(int i = 0; i < this->equation.length(); i++){
        NoobStack<char> temp;
        char newOP = this->equation[i];
        switch(newOP){
            case '(':
                op.push('(');
                break;
            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
            case ')':
                while(!this->op.isEmpty()){
                    char get = this->op.pop();
                    if(assignValue(get) <= assignValue(newOP)){
                        op.push(get);
                        op.push(newOP);
                        while(!temp.isEmpty())
                            op.push(temp.pop()
                        break;
                    } else {
                        temp.push(newOP);
                    }
                }
                break;
            default:
                int number = 0;
                while (1) {   
                    number *= 10;
                    number += newOP - '0';
                    
                    if(assignValue(this->equation[i+1] == -1001001))
                        newOP = this->equation[++i];
                    else break;                    
                }
                nums.push(number);
                break;
        };
    }
}








std::istream& operator >> (std::istream &in, MagicMaths obj){
    in >> obj.equation;
    return in;
}



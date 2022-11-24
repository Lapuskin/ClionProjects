#include <iostream>
#include <stdio.h>
#include "string"

using namespace std;

class Lexeme{
    string _name, _const;
    Lexeme* _lec;
    int _val;
public:
    Lexeme* _childrenLeft;
    Lexeme* _childrenRight;
    Lexeme* _parent;

    Lexeme(string name){
        this->_name = name;
    };

public:
    int calc(){

    };
};

class Plus : Lexeme{
    int calc() {
        return this->_childrenLeft->calc() + this->_childrenRight->calc();
    }
};
class Minus : Lexeme{
    int calc() {
        return this->_childrenLeft->calc() - this->_childrenRight->calc();
    }
};
class Multiply : Lexeme{
    int calc() {
        return this->_childrenLeft->calc() * this->_childrenRight->calc();
    }
};
class Division : Lexeme{
    int calc() {
        return this->_childrenLeft->calc() / this->_childrenRight->calc();
    }
};
class Constant : Lexeme{

};
class Variable : Lexeme{

};
int main(){}
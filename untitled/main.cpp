#include <iostream>
#include <stdio.h>
#include "string"
#include "vector"

using namespace std;

template<class Lex>
class Tree{
class Lexeme{
    string _const;
    vector<string> _lec;
    int _val;
public:
    Lexeme(Lex* parent, Lex* chLeft, Lex* chRight){
        _parent = parent;
        _childrenLeft = chLeft;
        _childrenRight = chRight;
    };
    Lex* _childrenLeft;
    Lex* _childrenRight;
    Lex* _parent = nullptr;
    virtual int calc(){};
};
    int Priority(string str){
        if(str == "+"|| str == "-") return 3;
        else if(str == "/"|| str == "*") return 2;
        else if(str == "sin"|| str == "pow"|| str == "cos"|| str == "pow" || str == "sqrt") return 1;
        else
            return 0;
    };
    Lex* Inflection(vector<string> lec, Lex* parent){
        vector <string> left, right;
        int priority = 0, maxpriority = 0, place = 0;
        for (int i = 0; i < lec.size(); ++i) {
            if(lec[i] == "(")
                priority--;
            else if(lec[i] == ")")
                priority++;
            priority = Priority(lec[i]);
            if(maxpriority < priority) {
                maxpriority = priority;
                place = i;
            }
        }
        //делим лексемы по сторонам
        for (int i = 0; i < place; ++i)
            left.push_back(lec[i]);
        for (int i = place + 1; i < lec.size(); ++i)
            right.push_back(lec[i]);

        //создаем узел нужного типа, устанавливаем значени полей и возвращаем указатель на узел.
        if(lec[place] == "+") {
            Plus* node = new Plus (parent, Inflection(left, this), Inflection(right, this));
            return node;
        }
        else if(lec[place] == "-") {
            Minus* node = new Minus(parent, Inflection(left, this), Inflection(right, this));
            return node;}
        else if(lec[place] == "/") {
            Division* node = new Division(parent, Inflection(left, this), Inflection(right, this));
            return node;}
        else if(lec[place] == "*") {
            Multiply* node = new Multiply(parent, Inflection(left, this), Inflection(right, this));
            return node;}
        else if(lec[place] == "sin"|| lec[place] == "pow"|| lec[place] == "cos"|| lec[place] == "pow" || lec[place] == "sqrt") {
            Func* node = new Func(parent, Inflection(left, this), Inflection(right, this));
            return node;}
        else {
            Constant *node = new Constant(parent, nullptr, nullptr);
            return *node;
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
class Func: Lexeme{};

vector<string> SplitLex(string str){
    vector<string> lexem;
    string temp = "";
    for (int i = 0; i < str.size(); ++i) {
        if(str[i] == ' ') {
            lexem.push_back(temp);
            temp = "";
        }
        else temp += str[i];
    }
    lexem.push_back(temp);
    return lexem;
}

    Lex* _root;
public:
    template<class Lex1>
    Tree(string lex){
        _root = Inflection(SplitLex(lex), nullptr);
    };

};

int main(){
    string s;
    getline(cin, s);
    Tree<class Lex> tree(s);
}
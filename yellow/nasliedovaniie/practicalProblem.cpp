#include <vector>
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Node {
public:
    virtual int evaluate() {
        return 0;
    }
};

class Digit : public Node {
public:
    Digit(int d) : d_(d) {}
    int evaluate() override { return d_;}
private:
    int d_;
};

class Variable : public Node {
public:
    Variable(const int& x) : x_(x) {}
    int evaluate() override {
        return x_;
    }
private:
    int x_;
};

class Operation : public Node {
public:
    Operation(char op, shared_ptr<Node> left, shared_ptr<Node> right) : op_(op), left_(left), right_(right) {}
    int evaluate() override {
        switch(op_){
            case '+': return left_->evaluate() + right_->evaluate();
            case '-': return left_->evaluate() - right_->evaluate();
            case '*': return left_->evaluate() * right_->evaluate();
            case '/': return left_->evaluate() / right_->evaluate();
        }
        return 0;
    }
private:
    const char op_;
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
};

// Node Parse(const string& token, int& x){

// }

int main(){
    string tokens = "5+7-x*x+x";    
    // cout << "Enter expression: ";
    cout << "Your expression: " << tokens << endl;
    // cin >> tokens;
    int x;
    cout << "Enter x: ";
    cin >> x;
    shared_ptr<Node> var1 = make_shared<Variable>(x);
    shared_ptr<Node> var2 = make_shared<Variable>(x);
    shared_ptr<Node> mul1 = make_shared<Operation>('*', var1, var2);

    shared_ptr<Node> digit1 = make_shared<Digit>(5);
    shared_ptr<Node> digit2 = make_shared<Digit>(7);

    shared_ptr<Node> var3 = make_shared<Variable>(x);

    shared_ptr<Node> add1 = make_shared<Operation>('+', digit1, digit2);
    shared_ptr<Node> sub1 = make_shared<Operation>('-', add1, mul1);
    shared_ptr<Node> add2 = make_shared<Operation>('+', sub1, var3);

    cout << add2->evaluate() << endl;
    // int x;
    // auto expr = Parse(tokens, x);
    // cout << "Enter x: ";
    // while(cin >> x){
    //     cout << expr->evaluate() << endl;
    //     cout << "Enter x: ";
    // }

    return 0;
}
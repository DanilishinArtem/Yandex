#include <iostream>
#include <string>

using namespace std;

struct Fruit{
    int health = 0;
    string type = "fruit";
};

struct Apple: public Fruit{
    Apple(){
        health = 10;
        type = "apple";
    }
};

struct Orange: public Fruit{
    Orange(){
        health = 5;
        type = "orange";
    }
};

class Animal{
public:
    string type = "animal";

    void eat(const Fruit& fruit){
        cout << type << " eats " << fruit.type << ". " << fruit.health << " health left" << endl;
    }
};

class Cat: public Animal{
public:
    Cat(){
        type = "cat";
    }
    void meow(){
        cout << "meow" << endl;
    }
};

class Dog: public Animal{
public:
    Dog(){
        type = "dog";
    }
};

void DoMeal(Animal& animal, const Fruit& fruit){
    animal.eat(fruit);
}

int main(){
    Apple apple;
    Orange orange;
    Cat cat;
    Dog dog;
    cat.meow();
    DoMeal(cat, apple);
    DoMeal(dog, orange);
    return 0;
}


// F:\c-plus-plus-modern-development\c-plus-plus-yellow\05_nasliedovaniie-i-polimorfizm\01_nasliedovaniie
// [2]
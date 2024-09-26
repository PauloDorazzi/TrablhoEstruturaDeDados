#pragma once
#include <string>
using namespace std;
class Element {
protected:
    string name;
public:
    Element(string name) : name(name) {}
    virtual ~Element() {}
    string getName() { return name; }
};

class Weapon : public Element {
private:
    int attackPower;
public:
    Weapon(string name, int attackPower) : Element(name), attackPower(attackPower) {}
    int getAttackPower() { return attackPower; }
};

class Potion : public Element {
private:
    int healAmount;
public:
    Potion(string name, int healAmount) :  Element(name), healAmount(healAmount) {}
    int getHealAmount() { return healAmount; }
};

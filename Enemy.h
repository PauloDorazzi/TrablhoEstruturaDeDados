
#include <string>

using namespace std;

class Enemy {
private:
    string name;
    int health;
    int attackPower;
public:
    Enemy(string name, int health, int attackPower) : name(name), health(health), attackPower(attackPower) {}

    bool isAlive() {
        return health > 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    int getAttack() {
        return attackPower;
    }
};

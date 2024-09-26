
#include <string>
#include <iostream>
#include "Element.h"
#include "Belt.h"
#include "Mochila.h"
#include "Enemy.h"

using namespace std;

class Hero {
private:
    string nome;
    int saude;
    Belt belt;
    Mochila mochila;

public:
    Hero(string nome, int saude) : nome(nome), saude(saude) {}

    void displayStatus() {
        cout << "Heroi: " << nome << " | Pontos de Vida: " << saude << endl;
        belt.displayContents();
        mochila.ItemTopo();
    }

    void Dano(int damage) {
        saude -= damage;
        if (saude < 0) saude = 0;
    }

    void cura(int amount) {
        saude += amount;   
    }

    bool Vivo() {
        return saude > 0;
    }

    string getName() { return nome; }
    int getHealth() { return saude; }

    void addItemToBelt(Element* item) {
        if (belt.addItem(item)) {
            cout << "Item " << item->getName() << " adicionado ao cinto.\n";
        }
        else {
            cout << "Cinto cheio! Não foi possível adicionar o item.\n";
        }
    }

    void addItemToBackpack(Element* item) {
        mochila.push(item);
        cout << "Item " << item->getName() << " adicionado à mochila.\n";
    }

    void batalha(Enemy& enemy) {
        while (this->Vivo() && enemy.isAlive()) {
            // Atacar o inimigo
            cout << "Herói atacou o inimigo!\n";
            enemy.takeDamage(10);  // Simplificado, usa uma arma do cinto
            if (enemy.isAlive()) {
                cout << "Inimigo atacou o herói!\n";
                this->Dano(enemy.getAttack());
            }
        }
    }
};


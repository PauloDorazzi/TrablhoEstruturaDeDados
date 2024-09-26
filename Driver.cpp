#include <iostream>
#include "Hero.h"
#include "Enemy.h"
#include "Element.h"
#include <fstream>

class Mapa {
private:
    int size;
    string* sqms;
public:
    Mapa(int size) : size(size) {
        sqms = new string[size];
        // Inicializando SQMs aleat�rios (vazio, inimigo ou item)
        for (int i = 0; i < size; i++) {

            int randVal = rand() % 3;

            if (randVal == 0) {
                sqms[i] = "Vazio";
            } else if (randVal == 1) {
                sqms[i] = "Inimigo";
            } else {
                sqms[i] = "Item";
            }
        }
    }

    ~Mapa() {
        delete[] sqms;
    }

    string getSQM(int index) {
        if (index >= 0 && index < size) {
            return sqms[index];
        }
        return "Inexistente";
    }

    int getSize() {
        return size;
    }
};

class DriverJogo {
private:
    Hero hero;
    Mapa mapa;
    int currentSQM;

public:
    DriverJogo(string heroName) : hero(heroName, 100), mapa(10), currentSQM(0) {}

    void startGame() {
       cout << "Bem-vindo ao jogo, " << hero.getName() << "!\n";

        while (hero.Vivo() && currentSQM < mapa.getSize()) {
            cout << "\nVoc� est� na posi��o " << currentSQM << " no mapa.\n";
            string sqmContent = mapa.getSQM(currentSQM);

            cout << "Voc� encontrou: " << sqmContent << "\n";

            if (sqmContent == "Inimigo") {
                Enemy enemy("Orc", 50, 10);  // Cria um inimigo "Orc" com 50 de vida e 10 de poder de ataque
              cout << "Prepare-se para a batalha!\n";
                hero.batalha(enemy);  // Engaja em batalha com o Orc

                if (!hero.Vivo()) {  // Verifica se o her�i ainda est� vivo ap�s a batalha
                    std::cout << "Voc� foi derrotado pelo inimigo!\n";
                    break;  // Sai do loop se o her�i estiver morto
                }
            }
            else if (sqmContent == "Item") {
                // A cria��o de objetos pode ser movida para fora do bloco if se for comum a v�rias ramifica��es
                Weapon* sword = new Weapon("Espada", 15);  // Criando dinamicamente para garantir persist�ncia fora do escopo
                cout << "Voc� encontrou uma espada! Deseja coloc�-la no cinto (1) ou na mochila (2)?\n";
                int choice;
                cin >> choice;
                if (choice == 1) {
                    hero.addItemToBelt(sword);
                }
                else {
                    hero.addItemToBackpack(sword);
                }
                // Considerar adicionar l�gica para evitar vazamento de mem�ria se a escolha for inv�lida
            }

            hero.displayStatus();

            // Pergunta ao jogador se deseja continuar
            cout << "Deseja continuar para o pr�ximo sqm? (1 - Sim / 2 - N�o): ";
            int action;
            cin >> action;

            if (action == 2) {
                break;
            }
            currentSQM++;
        }

        if (hero.Vivo()) {
           cout << "Parab�ns! Voc� completou o mapa.\n";
        } else {
           cout << "Voc� foi derrotado. Fim de jogo.\n";
        }

        saveScore();
    }

    void saveScore() {
       ofstream file("high_scores.txt", ios::app);
        if (file.is_open()) {
            file << hero.getName() << " alcan�ou o SQM " << currentSQM << " com " << hero.getHealth() << " pontos de vida restantes.\n";
            file.close();
            cout << "Pontua��o salva no arquivo 'high_scores.txt'.\n";
        } else {
            cout << "Erro ao abrir o arquivo de pontua��o.\n";
        }
    }
};

int main() {
    string playerName;
    cout << "Digite o nome do jogador: ";
    cin >> playerName;

    DriverJogo game(playerName);
    game.startGame();

    return 0;
}
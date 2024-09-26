
#include <iostream>
#include "Element.h"

class Mochila {
private:
    Element* stack[10];
    int top = -1;
public:
    void push(Element* item) {
        if (top < 9) {
            stack[++top] = item;
        }
    }

    Element* pop() {
        if (top >= 0) {
            return stack[top--];
        }
        return nullptr;
    }

    void ItemTopo() {
        if (top >= 0) {
            cout << "Mochila (topo): " << stack[top]->getName() << endl;
        } else {
            cout << "Mochila vazia.\n";
        }
    }
};


#include <iostream>
#include "Element.h"

using namespace std;

class Belt {
private:
    Element* items[3];
    int itemCount = 0;
public:
    bool addItem(Element* item) {
        if (itemCount < 3) {
            items[itemCount] = item;
            itemCount++;
            return true;
        }
        return false;
    }

    void displayContents() {
        cout << "Cinto: ";
        for (int i = 0; i < itemCount; i++) {
            cout << items[i]->getName() << " ";
        }
        cout << endl;
    }
};

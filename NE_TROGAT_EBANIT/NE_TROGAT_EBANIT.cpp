#include "Diolog_text.h"
#include "Library.h"

int test() {
    int a = 6;
    if (a == 5) {
        return 15;
    
    }
    else {
        return a;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    InitGame();
    one();
    //InitGirls();
    start();
    game();

    //cout << coffee_machine.size();
}

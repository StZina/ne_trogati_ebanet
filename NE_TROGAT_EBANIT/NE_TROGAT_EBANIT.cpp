﻿#include "Diolog_text.h"
#include "Library.h"


int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    one();
    InitGame();
    start();
    game();
}

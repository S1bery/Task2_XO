#include <iostream>
#include <vector>
#include <limits>

bool check (int y, int x) {
    if ((y >= 0 && y <= 2) && (x >= 0 && x <= 2)) {
        return true;
    } else {
        return false;
    }
}

void ignoreLine () {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    char XO[3][3] = {{'.', '.', '.'},
                     {'.', '.', '.'},
                     {'.', '.', '.'}}; // сделал точки, так проще ореинтироваться в консоле
    int y; // координата столбца
    int x; // координата строки
    int count = 9; // общее количество ходов
    bool endgame = false;
    char X_or_O = ' ';
    std::string total = "";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << XO[i][j] << " ";
        }
        std::cout << std::endl;
    } // изначальная отрисовка поля

    while (!endgame) {

        if (count % 2 != 0) {
            X_or_O = 'X';
        } else {
            X_or_O = 'O';
        }

        std::cout << "Enter coordinates for " << X_or_O << ": " << std::endl;
        std::cin >> y >> x;
        while (std::cin.fail() || !check(y, x) || XO[y][x] != '.'){
            std::cin.clear();
            ignoreLine ();
            std::cout << "Incorrect coordinates!" << std::endl;
            std::cout << "Enter coordinates for " << X_or_O << ": " << std::endl;
            if (std::cin.fail()) {
                std::cin.clear();
                ignoreLine ();
            }
            std::cin >> y >> x;
        }
        XO[y][x] = X_or_O;
        count -= 1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (XO[i][0] == X_or_O && XO[i][1] == X_or_O && XO[i][2] == X_or_O ||
                    XO[0][j] == X_or_O && XO[1][j] == X_or_O && XO[2][j] == X_or_O) {
                    total = " - win!";
                    total = X_or_O + total;
                    endgame = true;
                }
            }
        } // высчитывает победу

        if (count == 0) {
            total = "Nobody!";
            endgame = true;
        } // определяет ничью

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << XO[i][j] << " ";
            }
            std::cout << std::endl;
        }

    }
    std::cout << std::endl << total;
    return 0;
}

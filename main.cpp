#include <iostream>
#include <vector>

bool check (int y, int x) {
    if ((y >= 0 && y <= 2) && (x >= 0 && x <= 2)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char XO[3][3] = {{'.', '.', '.'},
                     {'.', '.', '.'},
                     {'.', '.', '.'}}; // сделал точки, так проще ореинтироваться в консоле
    int y; // координата столбца
    int x; // координата строки
    int count = 9; // общее количество ходов
    bool endgame = false;
    std::string X_or_O = "";
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
            while (!check(y, x) && XO[y][x] != '.'){
                std::cout << "Incorrect coordinates!" << std::endl;
                std::cout << "Enter coordinates for " << X_or_O << ": " << std::endl;
                std::cin >> y >> x;
            }
        XO[y][x] = X_or_O[0];
        count -= 1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (XO[i][0] == X_or_O[0] && XO[i][1] == X_or_O[0] && XO[i][2] == X_or_O[0] ||
                    XO[0][j] == X_or_O[0] && XO[1][j] == X_or_O[0] && XO[2][j] == X_or_O[0]) {
                    total = X_or_O + " - win!";
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

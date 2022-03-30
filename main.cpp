#include <iostream>
#include <vector>

int main() {
    char XO[3][3] = {{'.', '.', '.'},
                     {'.', '.', '.'},
                     {'.', '.', '.'}}; // сделал точки, так проще ореинтироваться в консоле
    int y; // координата столбца
    int x; // координата строки
    int count = 9; // общее количество ходов
    bool endgame = false;
    std::string total = "";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << XO[i][j] << " ";
        }
        std::cout << std::endl;
    } // изначальная отрисовка поля

    while (!endgame) {
        std::cout << "Enter coordinates for X: " << std::endl;
        std::cin >> y >> x;
            while (XO[y][x] != '.') {
                std::cout << "This point is occupied, enter other coordinates!" << std::endl;
                std::cout << "Enter coordinates for X: " << std::endl;
                std::cin >> y >> x;
            }
        XO[y][x] = 'X';
        count -= 1;
        if (count == 0) {
            total = "Nobody!";
            endgame = true;
        } // определяет ничью

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (XO[i][0] == 'X' && XO[i][1] == 'X' && XO[i][2] == 'X' ||
                    XO[0][j] == 'X' && XO[1][j] == 'X' && XO[2][j] == 'X') {
                    total = "X - win!";
                    endgame = true;
                }
            }
        } // высчитывает победу Х

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << XO[i][j] << " ";
            }
            std::cout << std::endl;
        }

        if (endgame) {
            break;
        } // дополнительная проверка на выход из основного while
        else {
            std::cout << "Enter coordinates for O: " << std::endl;
            std::cin >> y >> x;
            while (XO[y][x] != '.') {
                std::cout << "This point is occupied, enter other coordinates!" << std::endl;
                std::cout << "Enter coordinates for O: " << std::endl;
                std::cin >> y >> x;
            }
            XO[y][x] = 'O';
            count -= 1;
            if (count == 0) {
                total = "Nobody!";
                endgame = true;
            } // определяет ничью

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (XO[i][0] == 'O' && XO[i][1] == 'O' && XO[i][2] == 'O' ||
                        XO[0][j] == 'O' && XO[1][j] == 'O' && XO[2][j] == 'O') {
                        total = "O - win!";
                        endgame = true;
                    }
                }
            } // высчитывает победу O

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << XO[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        }

    std::cout << std::endl << total;
    return 0;
}

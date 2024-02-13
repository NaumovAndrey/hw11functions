#include <iostream>
#include <vector>
#include <string>

bool checkWinner(const std::vector<std::string>& board, char player) {
    // Проверка по строкам
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Есть победитель по строке
        }
    }

    // Проверка по столбцам
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Есть победитель по столбцу
        }
    }

    // Проверка по диагоналям
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true; // Есть победитель по диагонали
    }

    return false;  // Нет победителя
}

int main() {
    std::vector<std::string> board(3);

    for (int i = 0; i < 3; ++i) {
        std::cin >> board[i]; // Считываем строки игрового поля
    }

    // Проверка на некорректный ввод
    int crosses = 0, noughts = 0;
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == 'X') crosses++;
            else if (cell == 'O') noughts++;
        }
    }

    if (crosses < noughts || crosses > noughts + 1) {
        std::cout << "Incorrect" << std::endl;
        return 0;
    }

    // Проверка наличия победителя
    bool xWins = checkWinner(board, 'X');
    bool oWins = checkWinner(board, 'O');

    if (xWins && oWins) {
        std::cout << "Incorrect" << std::endl;
    } else if (xWins) {
        std::cout << "Petya won" << std::endl;
    } else if (oWins) {
        std::cout << "Vanya won" << std::endl;
    } else {
        std::cout << "Nobody" << std::endl;
    }

    return 0;
}

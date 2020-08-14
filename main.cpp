#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Node.h"
#include "Column.h"
#include "Cell.h"


struct Root {
    Column* left;
    Column* right;

    Root(Column* left, Column* right) : left(left), right(right) {};
};

int main() {
    //initial file reading
    std::ifstream txtFile;
    txtFile.open("sudoku.txt");
    std::string line;
    std::vector<std::vector<char>> grid;
    while (std::getline(txtFile, line)) {
        std::vector<char> row;
        for (char number : line) {
            if (number != ',') row.push_back(number);
        }
        grid.push_back(row);
    }
    txtFile.close();

    //initial 729x324 matrix
    std::vector<std::vector<Cell*>> matrix;
    matrix.reserve(729);

    std::vector<Column> columns;
    columns.reserve(324);
    for (int i = 1; i < 325; i++) {
        columns.emplace_back(Column(0, std::to_string(i)));
    }

    Root root(&columns[323], &columns[0]);

    for (int i = 1; i < 730; i++) {
        Cell first, second, third, fourth;
        std::vector<Cell*> row;
        row.push_back(&first);
        row.push_back(&second);
        row.push_back(&third);
        row.push_back(&fourth);
        matrix.push_back(row);

        //for second constraint
        int interval = (i % 81 != 0) ? i / 81 : i / 81 - 1;
        int start = 81 + 9 * interval;

        //first and second constraints
        if (i % 9 != 0) {
            first.addHeader(&columns[i / 9]);
            second.addHeader(&columns[start + (i % 9 - 1)]);
        } else {
            first.addHeader(&columns[(i / 9) - 1]);
            second.addHeader(&columns[start + 8]);
        }

        //horizontal linking
        first.addLeft(&fourth);
        first.addRight(&second);
        second.addLeft(&first);
        second.addRight(&third);
        third.addLeft(&second);
        third.addRight(&fourth);
        fourth.addLeft(&third);
        fourth.addRight(&first);
    }

}
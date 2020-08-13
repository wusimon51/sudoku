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
    std::vector<Column> columns;
    columns.reserve(324);
    for (int i = 1; i < 325; i++) {
        columns.emplace_back(Column(0, std::to_string(i)));
    }

    Root root(&columns[323], &columns[0]);

    for (int i = 1; i < 730; i++) {
        Cell first, second, third, fourth;
        if (i % 9 != 0) {
            first.addHeader(&columns[i / 9]);
        } else {
            first.addHeader(&columns[(i / 9) - 1]);
        }
    }


}
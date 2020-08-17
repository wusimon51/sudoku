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

void vertLink(Cell* cell, Column* col) {
    switch (col->size) {
        case 0:
            col->addDown(cell);
            cell->addUp(col);
        case 1:
            col->down->addDown(cell);
            cell->addUp(col->down);
        case 2:
            col->down->down->addDown(cell);
            cell->addUp(col->down->down);
        case 3:
            col->down->down->down->addDown(cell);
            cell->addUp(col->down->down->down);
        case 4:
            col->down->down->down->down->addDown(cell);
            cell->addUp(col->down->down->down->down);
        case 5:
            col->down->down->down->down->down->addDown(cell);
            cell->addUp(col->down->down->down->down->down);
        case 6:
            col->down->down->down->down->down->down->addDown(cell);
            cell->addUp(col->down->down->down->down->down->down);
        case 7:
            col->down->down->down->down->down->down->down->addDown(cell);
            cell->addUp(col->down->down->down->down->down->down->down);
        case 8:
            col->down->down->down->down->down->down->down->down->addDown(cell);
            cell->addUp(col->down->down->down->down->down->down->down->down);
            cell->addDown(col);
    }
}

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
    matrix.reserve(324);

    std::vector<Column> columns;
    columns.reserve(324);
    for (int i = 1; i < 325; i++) {
        columns.emplace_back(Column(0, std::to_string(i)));
    }

    Root root(&columns[323], &columns[0]);

    for (int i = 1; i < 2; i++) {
        Cell first, second, third, fourth;

        int interval; //for second constraint

        //third constraint
        int thirdStart = 162;
        if (i % 81 != 0) {
            interval = i / 81;
            third.addHeader(&columns[thirdStart + (i % 81 - 1)]);
        } else {
            interval = i / 81 - 1;
            third.addHeader(&columns[thirdStart + 80]);
        }

        //first and second constraints
        int secondStart = 81 + 9 * interval;
        if (i % 9 != 0) {
            first.addHeader(&columns[i / 9]);
            second.addHeader(&columns[secondStart + (i % 9 - 1)]);
        } else {
            first.addHeader(&columns[(i / 9) - 1]);
            second.addHeader(&columns[secondStart + 8]);
        }

        //fourth constraint
        interval = i % 243 != 0 ? i / 243 : i / 243 - 1;
        int subinterval = 0;
        for (int upper = 27; upper < 729; upper += 81) {
            if (i >= upper - 26 && i <= upper) {
                subinterval = 0;
                break;
            } else if (i > upper && i <= upper + 27) {
                subinterval = 1;
                break;
            } else if (i > upper + 27 && i <= upper + 54){
                subinterval = 2;
                break;
            }
        }
        int fourthStart = 243 + 27 * interval + 9 * subinterval;
        if (i % 9 != 0) {
            fourth.addHeader(&columns[fourthStart + i % 9 - 1]);
        } else {
            fourth.addHeader(&columns[fourthStart + 8]);
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

        //vertical linking
//        vertLink(&first, first.header);
    }

    for (int i = 0; i < 324; i++) {
        if (i == 0) {
            columns[i].addLeft(&columns[323]);
            columns[i].addRight(&columns[1]);
        } else if (i == 323) {
            columns[i].addLeft(&columns[322]);
            columns[i].addRight(&columns[0]);
        } else {
            columns[i].addLeft(&columns[i - 1]);
            columns[i].addRight(&columns[i + 1]);
        }
    }

}
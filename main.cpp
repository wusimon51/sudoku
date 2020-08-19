#include <iostream>
#include <fstream>
#include <vector>

#include "Node.h"
#include "Column.h"
#include "Cell.h"


struct Root {
    Column* left;
    Column* right;

    Root(Column* left, Column* right) : left(left), right(right) {};
};

void vertLink(Cell &cell, Column &col) {
    if (!col.down) {
        col.addDown(&cell);
        cell.addUp(&col);
    } else {
        Node* down = col.down;
        while (true) {
            if (!down->down) {
                break;
            } else {
                down = down->down;
            }
        }
        down->addDown(&cell);
        cell.addUp(down);
    }

    if (col.size == 9) {
        col.addUp(&cell);
        cell.addDown(&col);
    }
}

void cover(Column &col) {
    col.right->left = col.left;
    col.left->right = col.right;
    Node* i = col.down;
    while (i != &col) {
        Node* j = i->right;
        while (j != i) {
            j->down->up = j->up;
            j->up->down = j->down;
            Cell* cell = dynamic_cast<Cell*>(j);
            cell->header->size--;
            j = j->right;
        }
        i = i->down;
    }
}

void uncover(Column &col) {
    Node* i = col.up;
    while (i != &col) {
        Node* j = i->left;
        while (j != i) {
            Cell* cell = dynamic_cast<Cell*>(j);
            cell->header->size++;
            j->down->up == j;
            j->up->down = j;
            j = j->left;
        }
        i = i->up;
    }
    col.right->left = &col;
    col.left->right = &col;
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
    std::vector<Cell*> cellList;

    std::vector<Column> columns;
    columns.reserve(324);
    for (int i = 1; i < 325; i++) {
        columns.emplace_back(Column(0, std::to_string(i)));
    }

    Root root(&columns[323], &columns[0]);

    for (int i = 1; i < 730; i++) {
        Cell* first = new Cell;
        cellList.push_back(first);
        Cell* second = new Cell;
        cellList.push_back(second);
        Cell* third = new Cell;
        cellList.push_back(third);
        Cell* fourth = new Cell;
        cellList.push_back(fourth);

        int interval; //for second constraint

        //third constraint
        int thirdStart = 162;
        if (i % 81 != 0) {
            interval = i / 81;
            third->addHeader(&columns[thirdStart + (i % 81 - 1)]);
        } else {
            interval = i / 81 - 1;
            third->addHeader(&columns[thirdStart + 80]);
        }

        //first and second constraints
        int secondStart = 81 + 9 * interval;
        if (i % 9 != 0) {
            first->addHeader(&columns[i / 9]);
            second->addHeader(&columns[secondStart + (i % 9 - 1)]);
        } else {
            first->addHeader(&columns[(i / 9) - 1]);
            second->addHeader(&columns[secondStart + 8]);
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
            fourth->addHeader(&columns[fourthStart + i % 9 - 1]);
        } else {
            fourth->addHeader(&columns[fourthStart + 8]);
        }

        //horizontal linking
        first->addLeft(fourth);
        first->addRight(second);
        second->addLeft(first);
        second->addRight(third);
        third->addLeft(second);
        third->addRight(fourth);
        fourth->addLeft(third);
        fourth->addRight(first);

        //vertical linking
        vertLink(*first, *first->header);
        vertLink(*second, *second->header);
        vertLink(*third, *third->header);
        vertLink(*fourth, *fourth->header);
    }

    //linking columns
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

    //deallocating memory
    for (auto cell : cellList) {
        delete cell;
    }

}
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Node.h"
#include "Column.h"
#include "Root.h"


int main() {
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

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            if (grid[row][col] != '_') {
                Node node((int)(grid[row][col] - '0'));
            }
        }
    }

}
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Node.h"


struct Column : public Node {
    int size;
    Column(int size) : size(size) {};
};

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

    //initial 729x324 matrix
    Node root;
    Column start(0);
    start.addLeft(&root);

    for (int col = 0; col < 324; col++) {
        Column column(0);
    }

}
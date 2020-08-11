#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Node.h"


struct Column : public Node {
    int size;
};

struct Root {
    std::unique_ptr<Column> left;
    std::unique_ptr<Column> right;
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
    Root root;
    Node node(12);
    Node node2(5);
    node.header = static_cast<std::unique_ptr<Node>>(&node2);
    std::cout << node.header->value <<std::endl;
//    for (int col = 0; col < 324; col++) {
//
//    }

}
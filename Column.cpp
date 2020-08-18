#include "Column.h"


Column::Column(int size, std::string name) {
    this->size = size;
    this->name = std::move(name);
}
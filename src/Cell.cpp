#include "Cell.h"


void Cell::addHeader(Column* col) {
    this->header = col;
    this->header->size++;
}
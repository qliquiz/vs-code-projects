#include "figures.h"
#include "board.h"


Cell::Cell() : x(-1), y(-1) {}

Cell::Cell(int xx, int yy) : x(xx), y(yy) {}



Figure::Figure(int xx, int yy) : cell(xx, yy) {}



Rook::Rook(int xx, int yy) : Figure(xx, yy) {}


//bool Pawn::canTransform() { return (isWhite() && pos.y == 8) || (!isWhite() && pos.y == 1); }
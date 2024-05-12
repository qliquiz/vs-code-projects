#include <map>
#include <vector>
#include <ostream>


struct Cell {
	int x, y;

	Cell() : x(-1), y(-1) {}
	Cell(int xx, int yy) : x(xx), y(yy) {}
};


struct Move { Cell src, dst; };


// class ITransformable { public: virtual Figure transform() = 0; };


class Board;


class Figure {
	Cell cell;
protected:
	Cell pos;

	bool isWhite() const;
public:
	Figure(int xx, int yy) : cell(xx, yy) {}

	void moveTo(int xx, int yy);

	virtual std::vector<Move>* getMovesArray(const Board& board) = 0;
};


//class Pawn : public Figure, public ITransformable {
//	bool canTransform();
//};


class Rook : public Figure {
public:
	Rook(int xx, int yy) : Figure(xx, yy) {}

	virtual std::vector<Move>* getMovesArray(const Board& board);
};


/*class Player {
	Move* moveArray;
public:
	~Player();
};


class AIPlayer : public Player {
	BeginBase* beginBase;
public:
	~AIPlayer();
};

Player::~Player() { delete [] moveArray; }

AIPlayer::~AIPlayer() { delete beginBase; }*/
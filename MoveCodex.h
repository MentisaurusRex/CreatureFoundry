#pragma once
#include <vector>
#include "Move.h"

class MoveCodex
{
public:
	MoveCodex(void);
	~MoveCodex(void);

	void init();
	Move getMove(int index);

private:
	std::vector<Move> _moveList;
};


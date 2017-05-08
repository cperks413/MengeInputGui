#pragma once
#include "Square.h"

class AgentGroup
{
public:
	AgentGroup(Square spawnSquare);
	AgentGroup(Square spawn, Square destinationSquare, int AgentXNum, int AgentYNum);
	Square spawn;
	Square destination;
	int agentXNum, agentYNum;
};
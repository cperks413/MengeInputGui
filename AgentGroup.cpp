#include "AgentGroup.h"

AgentGroup::AgentGroup(Square spawnSquare)
{
	spawn = spawnSquare;
};

AgentGroup::AgentGroup(Square spawnSquare, Square destinationSquare, int AgentXNum, int AgentYNum)
{
	spawn = spawnSquare;
	destination = destinationSquare;
	agentXNum = AgentXNum;
	agentYNum = AgentYNum;
};
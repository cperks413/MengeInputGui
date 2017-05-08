#pragma once
#include <fstream>
#include <vector>
#include "AgentGroup.h"

class Writer
{
public:
	Writer();
	void Writer::write();
	void Writer::setFolderName(const char*);
	const char* Writer::getFolderName();
	std::vector<AgentGroup> agentGroupList;
	void Writer::addAgentGroup(AgentGroup);
	std::vector<Square> obstacleList;
	void Writer::addObstacle(Square);

private:
	const char* folderName;
	void Writer::makeMainXml();
	void Writer::makeBehaviour();
	void Writer::makeScene();
	void Writer::makeView();
	void Writer::writeAgentGroups(std::ofstream*);
	void Writer::writeObstacles(std::ofstream*);
};
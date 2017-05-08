#include "Writer.h"
#include <direct.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

Writer::Writer()
{
	setFolderName("noName");
};

void Writer::write()
{
	//make folders
	std::string strFolderName = folderName;
	std::string folderStringHolder = "core/" + strFolderName;
	mkdir("core");
	mkdir(folderStringHolder.c_str());

	//make files
	makeMainXml();
	makeBehaviour();
	makeScene();
	makeView();
};

void Writer::addAgentGroup(AgentGroup agentGroup)
{
	agentGroupList.push_back(agentGroup);
}

void Writer::setFolderName(const char* folderNameArg)
{
	folderName = folderNameArg;
};

const char* Writer::getFolderName()
{
	return folderName;
};

void Writer::makeMainXml()
{
	std::ofstream xmlFile;
	std::string strFolderName = folderName;
	xmlFile.open("core/" + strFolderName + ".xml");

	std::ifstream templateFile;
	templateFile.open("template/base.xml");

	std::string line;
	while (std::getline(templateFile, line))
	{
		std::istringstream iss(line);
		std::string writeString = iss.str();

		if (writeString == "sceneLine")
		{
			writeString = "scene=\"" + strFolderName + "/" + strFolderName + "S.xml\"";
		}
		else if (writeString == "behaviorLine")
		{
			writeString = "	behavior=\"" + strFolderName + "/" + strFolderName + "B.xml\"";
		}
		else if (writeString == "viewLine")
		{
			writeString = "	view=\"" + strFolderName + "/" + strFolderName + "V.xml\"";
		}

		xmlFile << writeString << "\n";
	}
};

void Writer::makeBehaviour()
{
	std::ofstream xmlFile;
	std::string strFolderName = folderName;
	xmlFile.open("core/" + strFolderName + "/" + strFolderName + "B.xml");

	std::ifstream templateFile;
	templateFile.open("template/base/baseB.xml");

	std::string line;
	while (std::getline(templateFile, line))
	{
		std::istringstream iss(line);
		std::string writeString = iss.str();

		if (writeString == "goalList")
		{
			for (int i = 0; i < agentGroupList.size() && i < 4; i++)
			{
				Square destSquare = agentGroupList.at(i).destination;
				xmlFile << "		<Goal type = \"AABB\" id = \"" + std::to_string(i)
					+ "\" min_x = \"" + std::to_string(destSquare.getMinX())
					+ "\" min_y = \"" + std::to_string(destSquare.getMinY())
					+ "\" max_x = \"" + std::to_string(destSquare.getMaxX())
					+ "\" max_y = \"" + std::to_string(destSquare.getMaxY())
					+ "\" />\n";
			}
			writeString = "";
		}

		if (writeString == "stateList")
		{
			for (int i = 0; i < agentGroupList.size() && i < 4; i++)
			{
				xmlFile << "	<State name = \"Walk" + std::to_string(i + 1) + "\" final = \"0\" >\n";
				xmlFile << "		<GoalSelector type=\"explicit\" goal_set=\"0\" goal=\"" + std::to_string(i) + "\"  />\n";
				xmlFile << "		<VelComponent type=\"goal\" />\n";
				xmlFile << "	</State>\n";
			}
			writeString = "";
		}

		if (writeString == "transitionList")
		{
			for (int i = 0; i < agentGroupList.size() && i < 4; i++)
			{
				xmlFile << "	<Transition from=\"Walk" + std::to_string(i + 1) + "\" to=\"Stop\" >\n";
				xmlFile << "		<Condition type=\"goal_reached\" distance=\"3\" />\n";
				xmlFile << "	</Transition>\n";
			}
			writeString = "";
		}

		xmlFile << writeString << "\n";
	}
}

void Writer::makeScene()
{
	std::ofstream xmlFile;
	std::string strFolderName = folderName;
	xmlFile.open("core/" + strFolderName + "/" + strFolderName + "S.xml");

	std::ifstream templateFile;
	templateFile.open("template/base/baseS.xml");

	std::string line;
	while (std::getline(templateFile, line))
	{
		std::istringstream iss(line);
		std::string writeString = iss.str();
		if (writeString == "AgentGroups")
		{
			writeAgentGroups(&xmlFile);
			writeString = "";
		}
		else if (writeString == "Obstacles") {
			writeObstacles(&xmlFile);
			writeString = "";
		}
		xmlFile << writeString << "\n";
	}
};
void Writer::makeView()
{
	std::ofstream xmlFile;
	std::string strFolderName = folderName;
	xmlFile.open("core/" + strFolderName + "/" + strFolderName + "V.xml");

	std::ifstream templateFile;
	templateFile.open("template/base/baseV.xml");

	std::string line;
	while (std::getline(templateFile, line))
	{
		std::istringstream iss(line);
		xmlFile << iss.str() << "\n";
	}
};

void Writer::writeAgentGroups(std::ofstream* file)
{
	std::ifstream agentGroupTemplate;
	agentGroupTemplate.open("template/base/agentGroup.xml");

	for (int i = 0; i < agentGroupList.size() && i < 4; i++)
	{
		AgentGroup ag = agentGroupList.at(i);
		Square spawnSquare = ag.spawn;
		agentGroupTemplate.clear();
		agentGroupTemplate.seekg(0, std::ios::beg);
		std::string line;
		while (std::getline(agentGroupTemplate, line))
		{
			std::istringstream iss(line);
			std::string writeString = iss.str();
			if (writeString == "stateSelector")
			{
				writeString = "	<StateSelector type=\"const\" name = \"Walk" + std::to_string(i + 1) + "\" />";
			}
			else if (writeString == "profileSelector")
			{
				writeString = "<ProfileSelector type=\"const\" name= \"group" + std::to_string((i + 1)) + "\" />";
			}
			else if (writeString == "anchor")
			{
				writeString = "				anchor_x=\"" + std::to_string(spawnSquare.x) + "\" anchor_y=\"" + std::to_string(spawnSquare.y) + "\" ";
			}
			else if (writeString == "offset")
			{
				float offsetValueX;
				float offsetValueY;
				offsetValueX = spawnSquare.offsetX / ag.agentXNum;
				offsetValueY = spawnSquare.offsetY / ag.agentYNum;
				writeString = "				offset_x=\"" + std::to_string(offsetValueX) + "\" offset_y=\"" + std::to_string(offsetValueY) + "\" ";
			}
			else if (writeString == "agents")
			{
				writeString = "				count_x=\"" + std::to_string(ag.agentXNum) + "\" count_y=\"" + std::to_string(ag.agentYNum) + "\"";
			}
			*file << writeString << "\n";
		}
	}
};

void Writer::writeObstacles(std::ofstream* xmlFile)
{
	for (int i = 0; i < obstacleList.size(); i++)
	{
		*xmlFile << "<Obstacle closed=\"1\"  >\n";
		*xmlFile << "<Vertex p_x = \"" + std::to_string(obstacleList.at(i).getMinX())
			+ "\" p_y = \"" + std::to_string(obstacleList.at(i).getMinY()) + "\" />\n";
		*xmlFile << "<Vertex p_x = \"" + std::to_string(obstacleList.at(i).getMaxX())
			+ "\" p_y = \"" + std::to_string(obstacleList.at(i).getMinY()) + "\" />\n";
		*xmlFile << "<Vertex p_x = \"" + std::to_string(obstacleList.at(i).getMaxX())
			+ "\" p_y = \"" + std::to_string(obstacleList.at(i).getMaxY()) + "\" />\n";
		*xmlFile << "<Vertex p_x = \"" + std::to_string(obstacleList.at(i).getMinX())
			+ "\" p_y = \"" + std::to_string(obstacleList.at(i).getMaxY()) + "\" />\n";
		*xmlFile << "</Obstacle>\n";
	}
}

void Writer::addObstacle(Square square)
{
	obstacleList.push_back(square);
}
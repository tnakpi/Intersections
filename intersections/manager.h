#pragma once
#include "roads.h"

class Manager {
public:
	Manager(int length);
	void MoveAll();
	void Draw();
private:
	std::vector<std::shared_ptr<Lane>> lanes;
	Interchange interchange;
};

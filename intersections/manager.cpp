#include "manager.h"

using namespace std;

Manager::Manager(int length) {
	lanes.resize(8);
	lanes[0] = shared_ptr<Lane>(new Lane(length, Direction::Up));
	lanes[1] = shared_ptr<Lane>(new Lane(length, Direction::Down));
	lanes[2] = shared_ptr<Lane>(new Lane(length, Direction::Right));
	lanes[3] = shared_ptr<Lane>(new Lane(length, Direction::Left));
	lanes[4] = shared_ptr<Lane>(new Lane(length, Direction::Up));
	lanes[5] = shared_ptr<Lane>(new Lane(length, Direction::Down));
	lanes[6] = shared_ptr<Lane>(new Lane(length, Direction::Right));
	lanes[7] = shared_ptr<Lane>(new Lane(length, Direction::Left));
	interchange = Interchange(lanes[0]->GetEntrance(), lanes[1]->GetEntrance(), lanes[2]->GetEntrance(), lanes[3]->GetEntrance());
}

void Manager::MoveAll() {
	for (size_t i = 0; i < 4; i++) {
		lanes[i]->MoveCars();
	}
}

void Manager::Draw() {

}

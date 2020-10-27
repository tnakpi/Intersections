#include "roads.h"
#include <memory>

using namespace std;

Lane::Lane(size_t len, Direction d, shared_ptr<Cell> entrance_ptr) : length(len) {
	cells.resize(length + 1);
	for (auto& i : cells) {
		i = make_shared<Cell>();
	}
	cells[0] = shared_ptr<Entrance>(new Entrance(d));
	cells[length - 1] = shared_ptr<Exit>(new Exit(entrance_ptr));
	cells[length] = make_shared<Cell>();
	direction = d;
}

void Lane::MoveCars() {
	for (size_t i = 0; i < length; i++) {
		i = MoveCar(i);
	}
}

size_t Lane::get_lenght() const {
	return length;
}

const vector<shared_ptr<Cell>>& Lane::get_vector() const {
	return cells;
}

shared_ptr<Cell>& Lane::GetEntrance() {
	return cells[0];
}

size_t Lane::MoveCar(size_t idx) {
	if (cells[idx]->IsEmpty()) return idx;
	if (cells[idx + 1]->IsEmpty()) {
		cells[idx + 1]->InsertCar(cells[idx]->ExtractCar());
		return idx + 1;
	}
	else {
		size_t new_idx = MoveCar(idx + 1);
		if (cells[idx + 1]->IsEmpty()) {
			cells[idx + 1]->InsertCar(cells[idx]->ExtractCar());
		}
		return new_idx;
	}
}

bool Lane::InsertCar(queue<Direction> route, int sp, int max_sp) {
	return cells[0]->InsertCar(make_unique<Car>(direction, route, sp, max_sp));
}

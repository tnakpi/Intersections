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

TrafficLight::TrafficLight(size_t d, Light c_state, Light n_state) : delay(d), cur_state(c_state), next_state(n_state) {
}

Light TrafficLight::Count() {
	if (counter == delay - 1) {
		counter++;
		return Light::Yellow;
	}
	if (counter == delay) {
		swap(cur_state, next_state);
		counter = 0;
	}
	counter++;
	return cur_state;
}

Interchange::Interchange(size_t traffic_light_delay) : traf_h(traffic_light_delay, Light::Red, Light::Green), traf_v(traffic_light_delay, Light::Green, Light::Red) {

}

Interchange::Interchange(std::shared_ptr<Cell> u, std::shared_ptr<Cell> d,
	std::shared_ptr<Cell> l, std::shared_ptr<Cell>r,
	size_t traffic_light_delay) : traf_h(traffic_light_delay, Light::Red, Light::Green), traf_v(traffic_light_delay, Light::Green, Light::Red) {
	grid.resize(4);
	for (auto& row : grid) {
		row.resize(4);
	}
	grid[1][0] = make_shared<Exit>(l);
	grid[3][1] = make_shared<Exit>(d);
	grid[0][2] = make_shared<Exit>(u);
	grid[2][3] = make_shared<Exit>(r);
	grid[2][0] = make_shared<IntEntrance>(Direction::Right);
	grid[3][2] = make_shared<Entrance>(Direction::Up);
	grid[0][2] = make_shared<Entrance>(Direction::Down);
	grid[1][3] = make_shared<Entrance>(Direction::Left);


}

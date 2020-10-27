#include "car.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Car& c)
{
	os << "speed  " << c.GetSpeed() << std::endl;
	os << "max_speed  " << c.GetMaxSpeed() << std::endl;
	return os;
}

int Car::GetMaxSpeed() const {
	return max_speed;
}

int Car::GetSpeed() const {
	return speed;
}

//Driver::Driver(bool b_r, int w_s) : break_rules(b_r), wanted_speed(w_s) {
//}

Car::Car(Direction d, std::queue<Direction> r, int sp, int max_sp) : speed(sp), max_speed(max_sp), direction(d) {
	route = move(r);
}

Car::~Car() {
	//std::cerr << "Finished\n";
}

void Car::ChangeDirection(Direction dir) {
	direction = dir;
}

void Car::Gas() {
	if (speed != max_speed) {
		speed++;
	}
}

void Car::Break() {
	if (speed != 0) {
		speed--;
	}
}

void Car::SetVectorSpeed() {
	if (direction == Direction::Up) {
		v_speed = { 0, speed };
	}
	else if (direction == Direction::Down) {
		v_speed = { 0, -speed };
	}
	else if (direction == Direction::Right) {
		v_speed = { speed, 0 };
	}
	else {
		v_speed = { -speed, 0 };
	}
}

Direction Car::GetNextDirection() const {
	return route.size() != 0 ? route.front() : direction;
}

void Car::UpdateDirection() {
	if (route.size() != 0) {
		direction = route.front();
		route.pop();
	}
}

Vector Car::GetVectorSpeed() const {
	return v_speed;
}

void Car::SetDesiredCoords(int x, int y) {
	desired_coords = { x, y };
}

Vector Car::GetDesiredCoords() const {
	return desired_coords;
}

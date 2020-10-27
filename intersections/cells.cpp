#include "cells.h"
#include "car.h"

using namespace std;

bool Cell::InsertCar(unique_ptr<Car> c) {
	if (car == nullptr) {
		car = move(c);
		return true;
	}
	else {
		return false;
	}
}

bool Cell::IsEmpty() {
	return car == nullptr;
}

unique_ptr<Car> Cell::ExtractCar() {
	return move(car);
}

unique_ptr<Car> Exit::ExtractCar() {
	if (entrance == nullptr) {
		car.reset();
		cerr << "Extracted";
	}
	else if (entrance->IsEmpty()) {
		entrance->InsertCar(move(car));
	}
	return nullptr;
}

Entrance::Entrance(Direction d) : direction(d) {
}

Direction Entrance::GetDirection() const {
	return direction;
}

bool Entrance::InsertCar(std::unique_ptr<Car> c) {
	if (car == nullptr) {
		c->ChangeDirection(direction);
		car = move(c);
		return true;
	}
	else {
		return false;
	}
}

Exit::Exit(shared_ptr<Cell> c) {
	entrance = c;
}

Exit::Exit() {

}

IntEntrance::IntEntrance(Direction d) : Entrance(d) {
}

bool IntEntrance::InsertCar(std::unique_ptr<Car> c) {
	return true;
}
std::unique_ptr<Car> IntEntrance::ExtractCar() {
	queue<Direction> q;
	q.push(Direction::Left);
	return make_unique<Car>(Car(Direction::Down, q));
}
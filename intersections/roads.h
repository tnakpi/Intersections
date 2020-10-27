#pragma once
#include <vector>
#include <memory>

#include "cars.h"
#include "cells.h"


class Lane {
public:
	Lane(size_t len, Direction d, std::shared_ptr<Cell> exit_ptr = nullptr);
	void MoveCars();
	bool InsertCar(std::queue<Direction> route, int sp = 1, int max_sp = 1);
	std::shared_ptr<Cell>& GetEntrance();
	size_t get_lenght() const;
	const std::vector<std::shared_ptr<Cell>>& get_vector() const;
private:
	size_t MoveCar(size_t idx);
	Direction direction;
	size_t length;
	std::vector<std::shared_ptr<Cell>> cells;
};

enum class Light {
	Red,
	Yellow,
	Green
};

class TrafficLight {
public:
	TrafficLight(size_t d, Light c_state, Light n_state);
	Light Count();
private:
	Light cur_state;
	Light next_state;
	size_t counter = 0;
	size_t delay;
};


class Interchange {
public:
	Interchange(size_t traffic_light_delay = 5);
	Interchange(std::shared_ptr<Cell> u, std::shared_ptr<Cell> d,
		std::shared_ptr<Cell> l, std::shared_ptr<Cell>r,
		size_t traffic_light_delay = 5);
private:
	std::vector<std::vector<std::shared_ptr<Cell>>> grid;
	TrafficLight traf_v, traf_h;


};

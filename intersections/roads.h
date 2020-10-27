#pragma once
#include <vector>
#include <memory>

#include "car.h"
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
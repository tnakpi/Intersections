#pragma once
#include <iostream>
#include <vector>
#include <queue>

enum class Direction {
	Up,
	Down,
	Left,
	Right
};

struct Vector {
	int x;
	int y;
};

class Car
{
public:
	Car(Direction d, std::queue<Direction> r, int sp = 1, int max_sp = 1);
	~Car();
	//Car() {CUSTOM SETTINGS};
	int GetSpeed() const;
	int GetMaxSpeed() const;
	void Gas();
	void ChangeDirection(Direction dir);
	Direction GetNextDirection() const;
	void UpdateDirection();
	void Break();
	void SetVectorSpeed();
	Vector GetVectorSpeed() const;
	void SetDesiredCoords(int x, int y);
	Vector GetDesiredCoords() const;
private:

	//int acceleration;
	//int stopping_distance;
	Direction direction;
	std::queue<Direction> route;
	Vector v_speed;
	int speed;
	int max_speed;
	Vector desired_coords;
	//Driver driver;
};

//class Driver
//{
//public:
//	Driver(bool b_r, int w_s);
//private:
//	bool break_rules = false;
//	int wanted_speed;
//	//int starting_point;
//	//int end_point;
//};

std::ostream& operator<<(std::ostream& os, const Car& c);

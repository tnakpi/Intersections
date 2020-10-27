#pragma once
#include "cars.h"


class Cell {
public:
	virtual bool InsertCar(std::unique_ptr<Car> c);
	virtual std::unique_ptr<Car> ExtractCar();
	virtual bool IsEmpty();
protected:
	std::unique_ptr<Car> car;
	
};

class Entrance : public Cell {
public:
	Entrance(Direction d);
	virtual Direction GetDirection() const;
	virtual bool InsertCar(std::unique_ptr<Car> c) override;
protected:
	Direction direction;
};

class Exit : public Cell {
public:
	virtual std::unique_ptr<Car> ExtractCar() override;
	Exit(std::shared_ptr<Cell> c);
	Exit();
protected:
	std::shared_ptr<Cell> entrance;    
};

class IntEntrance : public Entrance {
public:
	IntEntrance(Direction d);
	virtual bool InsertCar(std::unique_ptr<Car> c) override;
	virtual std::unique_ptr<Car> ExtractCar() override;
};

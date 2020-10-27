#include <Windows.h>
#include <iostream>
#include "graphics.h"
#include "roads.h"

using namespace std;

int main()
{
	Manager man(5);
	Lane lane1(5, Direction::Up);

	Lane lane2(20, Direction::Left, lane1.GetEntrance());
	queue<Direction> q;
	q.push(Direction::Left);
	lane2.InsertCar(q);

	while (true)
	{
		Graphics(lane2);
		lane2.MoveCars();
		Sleep(500);
		system("cls");
	}


	//TrafficLight tr(3);
	//for (int i = 0; i < 20; i++) {
		//cout << static_cast<int>(tr.Count()) << endl;
	//}
	std::cout << "Success!!!";
}

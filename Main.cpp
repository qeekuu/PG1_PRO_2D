#include <iostream>
#include "Engine.h"
#include "Input.h"
#include "Point2D.h"
#include "LineSegment.h"
int main(int argc, char* argv[])
{
		Engine::getInstance()->Init();
		Point2D Point(400,300);
		PrimitiveRenderer rectangle;
		PrimitiveRenderer triangle;
		PrimitiveRenderer line_p;
		LineSegment line(500, 100, 600, 200);
		std::cout << "X: " << line.getStart().getCoordinates('X') << std::endl;
		std::cout << "Y: " << line.getStart().getCoordinates('Y') << std::endl;
		std::cout << "X2: " << line.getEnd().getCoordinates('X') << std::endl;
		std::cout << "Y2: " << line.getEnd().getCoordinates('Y') << std::endl;
	while (Engine::getInstance()->running()==true)
	{
		Engine::getInstance()->update();
		PrimitiveRenderer::setWindowColor(0, 0, 0, 255);

		Point.draw_point(124,153,60,255,Point.getCoordinates('X'), Point.getCoordinates('Y'));

		rectangle.draw_rectangle(0, 255, 0, 255, 400, 400, 100, 100);

		triangle.draw_triangle(255, 0, 0, 255, 100, 100, 200, 150, 150, 250);

		line_p.draw_line(255, 0, 0, 255, 600, 100, 700, 300);

		PrimitiveRenderer::render();
	}
	Engine::getInstance()->close();
	return 0;
}
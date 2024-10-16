#include <iostream>
#include "Engine.h"
#include "Input.h"
int main(int argc, char* argv[])
{
		Engine::getInstance()->Init();
	while (Engine::getInstance()->running()==true)
	{
		Engine::getInstance()->update();
		PrimitiveRenderer::setWindowColor(0, 0, 0, 255);

		PrimitiveRenderer point;
		point.draw_point(255, 0, 0, 255);

		PrimitiveRenderer rectangle;
		rectangle.draw_rectangle(0, 255, 0, 255, 400, 400, 100, 100);

		PrimitiveRenderer triangle;
		triangle.draw_triangle(255, 0, 0, 255, 100, 100, 200, 150, 150, 250);

		PrimitiveRenderer line;
		line.draw_line(255, 0, 0, 255, 600, 100, 700, 300);

		PrimitiveRenderer::render();
	}
	Engine::getInstance()->close();
	return 0;
}
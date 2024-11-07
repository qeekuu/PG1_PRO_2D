#include <iostream>
#include "Engine.h"
#include "Input.h"
#include "Point2D.h"
#include "LineSegment.h"
int main(int argc, char* argv[])
{
		Engine::getInstance()->Init();
		Point2D Point(400,300);
		PrimitiveRenderer pointR;
		PrimitiveRenderer lineR;
		PrimitiveRenderer rectangle;
		PrimitiveRenderer triangle;
		PrimitiveRenderer fillRenderer;
		PrimitiveRenderer line_p;
		PrimitiveRenderer circle;
		PrimitiveRenderer polygon;
		LineSegment line(300, 100, 400, 500);
		
	while (Engine::getInstance()->running()==true)
	{
		Engine::getInstance()->update();
		PrimitiveRenderer::setWindowColor(0, 0, 0, 255);
		pointR.draw_point(124, 153, 60, 255, Point.getCoordinates('X'), Point.getCoordinates('Y'));

		rectangle.draw_rectangle(0, 0, 255, 255, 400, 100, 600, 100, 600, 300, 400, 300);

		

		line_p.draw_line(255, 0, 0, 255, 700, 100, 700, 300);
		//lineR.draw_line(255,0,255,255,line.getStart().getCoordinates('X'), line.getStart().getCoordinates('Y'), line.getEnd().getCoordinates('X'), line.getEnd().getCoordinates('Y'));
		circle.draw_circle(255, 255, 255, 255, 500, 500, 70);
		std::vector<Point2D> points =
		{
			Point2D(100,100),
			Point2D(150,186),
			Point2D(250,186),
			Point2D(300,100),
			Point2D(250,14),
			Point2D(150,14)
		};
		
		/*std::vector<Point2D> points =
		{
			Point2D(100,100),
			Point2D(200,150),
			Point2D(150,186),
			Point2D(300,50),
			Point2D(150,14),
			Point2D(250,100)
		};*/
		SDL_Color fillColor = PrimitiveRenderer::fillColor(255, 0, 0, 255);
		SDL_Color boundaryColor = PrimitiveRenderer::boundaryColor(0, 0, 255, 255);
		SDL_Color fillColor_2 = PrimitiveRenderer::fillColor(0,255,0,255);
		SDL_Color boundaryColor_2 = PrimitiveRenderer::boundaryColor(255, 255, 255, 255);
		SDL_Color fillColor_3 = PrimitiveRenderer::fillColor(0, 255, 0, 255);
		SDL_Color boundaryColor_3 = PrimitiveRenderer::boundaryColor(210, 50, 20, 255);
		PrimitiveRenderer::draw_polygon(210,50,20,255,points,polygon);
		triangle.draw_triangle(255, 255, 0, 255, 100, 200, 200, 250, 150, 350);
		circle.RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(),500,500,fillColor_2,boundaryColor_2);
		fillRenderer.RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(), 500, 200, fillColor, boundaryColor);
		polygon.RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(),199,102,fillColor_3,boundaryColor_3);
		PrimitiveRenderer::render();
	}
	Engine::getInstance()->close();
	return 0;
}
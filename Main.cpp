#include <iostream>
#include <ostream>
#include "Engine.h"
#include "Input.h"
#include "Player.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Ellipse.h"

int main(int argc, char* argv[])
{
	// pomocnicze
	bool translated = false;
	bool rotated = false;
	bool rotatedPoint = false;
	bool scale = false;
	bool scalePoint = false;
	Point2D r1(400, 100);
	Point2D r2(600, 100);
	Point2D r3(600, 300);
	Point2D r4(400, 300);
		std::vector<Point2D> points =
		{
			Point2D(100,100),
			Point2D(150,186),
			Point2D(250,186),
			Point2D(300,100),
			Point2D(250,14),
			Point2D(150,14)
		};


		Engine::getInstance()->Init();
		Point2D Point(400,300);
		PrimitiveRenderer pointR;
		PrimitiveRenderer lineR;
		Rectangle rectangle(0, 0, 255, 255, r1.getCoordinates('X'), r1.getCoordinates('Y'), r2.getCoordinates('X'), r2.getCoordinates('Y'), r3.getCoordinates('X'), r3.getCoordinates('Y'), r4.getCoordinates('X'), r4.getCoordinates('Y'));
		Triangle triangle(255, 255, 0, 255, 100, 200, 200, 250, 150, 350);
		PrimitiveRenderer fillRenderer;
		PrimitiveRenderer line_p;
		Circle circle(255, 255, 255, 255, 100, 100, 70);
		Polygon polygon(210, 50, 20, 255, points);
		LineSegment line(300, 100, 400, 500);
		Ellipse ellipse(255,0,0,255,400,500,70,40);

		// Player
		Player player(255, 0, 0, 255, 390, 290, 410, 290, 410, 310, 390, 310);
		
	while (Engine::getInstance()->running()==true)
	{
		
		Input::getInstances()->listen();
		if (Input::getInstances()->getKey(SDL_SCANCODE_W))
		{
			
			player.getRect().getPoint1().setCoordinatesY(player.getRect().getPoint1().getCoordinates('Y') - 1);
			player.getRect().getPoint2().setCoordinatesY(player.getRect().getPoint2().getCoordinates('Y') - 1);
			player.getRect().getPoint3().setCoordinatesY(player.getRect().getPoint3().getCoordinates('Y') - 1);
			player.getRect().getPoint4().setCoordinatesY(player.getRect().getPoint4().getCoordinates('Y') - 1);
			
		}
		if (Input::getInstances()->getKey(SDL_SCANCODE_S))
		{
			
			player.getRect().getPoint1().setCoordinatesY(player.getRect().getPoint1().getCoordinates('Y') + 1);
			player.getRect().getPoint2().setCoordinatesY(player.getRect().getPoint2().getCoordinates('Y') + 1);
			player.getRect().getPoint3().setCoordinatesY(player.getRect().getPoint3().getCoordinates('Y') + 1);
			player.getRect().getPoint4().setCoordinatesY(player.getRect().getPoint4().getCoordinates('Y') + 1);
			
		}
		if (Input::getInstances()->getKey(SDL_SCANCODE_A))
		{
			
			player.getRect().getPoint1().setCoordinatesX(player.getRect().getPoint1().getCoordinates('X') - 1);
			player.getRect().getPoint2().setCoordinatesX(player.getRect().getPoint2().getCoordinates('X') - 1);
			player.getRect().getPoint3().setCoordinatesX(player.getRect().getPoint3().getCoordinates('X') - 1);
			player.getRect().getPoint4().setCoordinatesX(player.getRect().getPoint4().getCoordinates('X') - 1);
			
		}
		if(Input::getInstances()->getKey(SDL_SCANCODE_D))
		{
			
			
			player.getRect().getPoint1().setCoordinatesX(player.getRect().getPoint1().getCoordinates('X') + 1);
			player.getRect().getPoint2().setCoordinatesX(player.getRect().getPoint2().getCoordinates('X') + 1);
			player.getRect().getPoint3().setCoordinatesX(player.getRect().getPoint3().getCoordinates('X') + 1);
			player.getRect().getPoint4().setCoordinatesX(player.getRect().getPoint4().getCoordinates('X') + 1);
			
		}
		if (Input::getInstances()->getButton(Input::LEFT_BUTTON))
		{
			std::cout << "Lewy przycisk \n";
		}
		if (Input::getInstances()->getButton(Input::RIGHT_BUTTON))
		{
			std::cout << "Prawy przycisk \n";
		}
		if (Input::getInstances()->getButton(Input::MIDDLE_BUTTON))
		{
			std::cout << "Srodkowy przycisk \n";
		}
		

		PrimitiveRenderer::setWindowColor(0, 0, 0, 255);
		//pointR.draw_point(124, 153, 60, 255, Point.getCoordinates('X'), Point.getCoordinates('Y'));
		//line_p.draw_line(255, 0, 0, 255, 700, 100, 700, 300);
		//lineR.draw_line(255,0,255,255,line.getStart().getCoordinates('X'), line.getStart().getCoordinates('Y'), line.getEnd().getCoordinates('X'), line.getEnd().getCoordinates('Y'));
		
		SDL_Color fillColor = PrimitiveRenderer::fillColor(255, 0, 0, 255);
		SDL_Color boundaryColor = PrimitiveRenderer::boundaryColor(0, 0, 255, 255);
		SDL_Color fillColor_2 = PrimitiveRenderer::fillColor(0,255,0,255);
		SDL_Color boundaryColor_2 = PrimitiveRenderer::boundaryColor(255, 255, 255, 255);
		SDL_Color fillColor_3 = PrimitiveRenderer::fillColor(0, 255, 0, 255);
		SDL_Color boundaryColor_3 = PrimitiveRenderer::boundaryColor(210, 50, 20, 255);
		SDL_Color fillColor_4 = PrimitiveRenderer::fillColor(0,255,255,255);
		SDL_Color boundaryColor_4 = PrimitiveRenderer::fillColor(255, 0, 0, 255);
		SDL_Color fillColor_5 = PrimitiveRenderer::fillColor(76, 140, 10, 255);
		SDL_Color boundaryColor_5 = PrimitiveRenderer::fillColor(255, 255, 0, 255);

		/* polygon.draw(); */
		/* triangle.draw(); */
		/* ellipse.draw(); */
		/* circle.draw(); */
		/* rectangle.draw(); */

		player.draw();
			
		/*if (!translated)
		{
			polygon.translate(150, 150);
			
			polygon.draw();
			translated = true;
		}*/

		
		/*if (!rotated)
		{
			polygon.rotate(30);
			polygon.draw();
			rotated = true;
		}*/
		
		/* if (!rotated) */
		/* { */
			/* polygon.rotate(30); */
			/* polygon.draw(); */
			/* rotated = true; */
		/* } */
		
		/*
		if (!rotatedPoint)
		{
			ellipse.rotatePoint(20, 15, 15);
			ellipse.draw();
			rotatedPoint = true;
		}
		*/
		
		/*if (!scale)
		{
			polygon.scale(2);
			polygon.draw();
			scale = true;
		}*/
		
		
		/*if (!scalePoint)
		{
			polygon.scalePoint(2, 1, 1);
			polygon.draw();
			scalePoint = true;
		}*/
		

		/* rectangle.fill(fillColor, boundaryColor); */
		/* circle.fill(fillColor_2,boundaryColor_2); */
		/* polygon.fill(fillColor_3, boundaryColor_3); */
		/* ellipse.fill(fillColor_4, boundaryColor_4); */
		/* triangle.fill(fillColor_5,boundaryColor_5); */

		PrimitiveRenderer::render();
		
		
		
	}

	Engine::getInstance()->close();
	return 0;
}

// Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
using namespace std;
using namespace sf;
using namespace sfp;
int main()
{
	int end = 1;

	while (end == 1)
	{

		// Create our window and world with gravity 0,1
		RenderWindow window(VideoMode(800, 600), "Bounce");
		World world(Vector2f(0, 1));

		// Create the ball
		PhysicsCircle ball;
		ball.setCenter(Vector2f(200, 200));
		ball.setRadius(20);
		world.AddPhysicsBody(ball);
		ball.applyImpulse(Vector2f(.3, .1));

		// Create the floor
		PhysicsRectangle floor;
		floor.setSize(Vector2f(800, 20));
		floor.setCenter(Vector2f(400, 590));
		PhysicsRectangle roof;
		roof.setSize(Vector2f(800, 20));
		roof.setCenter(Vector2f(400, 10));
		PhysicsRectangle rWall;
		rWall.setSize(Vector2f(20, 800));
		rWall.setCenter(Vector2f(10, 300));
		PhysicsRectangle lWall;
		lWall.setSize(Vector2f(20, 800));
		lWall.setCenter(Vector2f(790, 300));
		PhysicsRectangle block;
		block.setSize(Vector2f(100, 100));
		block.setCenter(Vector2f(400, 300));

		floor.setStatic(true);
		rWall.setStatic(true);
		lWall.setStatic(true);
		roof.setStatic(true);
		block.setStatic(true);
		world.AddPhysicsBody(floor);
		world.AddPhysicsBody(roof);
		world.AddPhysicsBody(lWall);
		world.AddPhysicsBody(rWall);
		world.AddPhysicsBody(block);
		int thudCount(1);
		int bangCount(1);
		floor.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
			cout << "thud " << thudCount << endl;
			thudCount++;
			};
		roof.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
			cout << "thud " << thudCount << endl;
			thudCount++;
			};
		lWall.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
			cout << "thud " << thudCount << endl;
			thudCount++;
			};
		rWall.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
			cout << "thud " << thudCount << endl;
			thudCount++;
			};
		block.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
			cout << "bang " << bangCount << endl;
			bangCount++;
			};

	
		Clock clock;
		Time lastTime(clock.getElapsedTime());

		while (end == 1) {
			// calculate MS since last frame
			Time currentTime(clock.getElapsedTime());
			Time deltaTime(currentTime - lastTime);
			int deltaTimeMS(deltaTime.asMilliseconds());
			if (deltaTimeMS > 0) {
				world.UpdatePhysics(deltaTimeMS);
				lastTime = currentTime;
			}
			window.clear(Color(0, 0, 0));
			window.draw(ball);
			window.draw(floor);
			window.draw(roof);
			window.draw(lWall);
			window.draw(rWall);
			window.draw(block);
			window.display();
			if (bangCount == 4) {
				end = 0;
			}
			
		}
		
	}
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

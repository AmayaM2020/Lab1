// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {
	string background = "backgrounds/winter.png";
	string foreground = "characters/yoda.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u az = foregroundImage.getSize();
	Vector2u sz = backgroundImage.getSize();
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			// These two loops will run the code inside for each pixel in
			//the background image
				// You can access the current pixel at x,y like so:
				Color exampleG = foregroundImage.getPixel((az.x-1),(az.y-1));
				Color greenColor(exampleG.r, exampleG.g, exampleG.b);
				//foregroundImage.setPixel(x, y, greenColor);

				Color back = backgroundImage.getPixel(x, y);
				Color Background(back.r, back.g, back.b);

				if ((foregroundImage.getPixel(x, y)) == greenColor) 
				{

					foregroundImage.setPixel(x, y, Background);

				}
			// Color objects store the individual channel values like
			//example.r example.g and example.b
		}
	}
	// By default, just show the foreground image

	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
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

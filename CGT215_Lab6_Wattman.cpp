// CGT215_Lab6_Wattman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Written by Jayy Wattman for a class lab to put greeenscreened characters on a different background

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


int main()
{
    string background = "images/backgrounds/winter.png"; //accesses background image, can be easily swapped for different image if need be
    string foreground = "images/characters/Rey.png"; //same as above but for the foreground/character image

    Texture backgroundTex;
    if (!backgroundTex.loadFromFile(background)) //let's you know if it couldn't find the image file where you said it would be
    {
        cout << "Couldn't Load Background Image" << endl;
        exit(1);
    }

    Texture foregroundTex;
    if (!foregroundTex.loadFromFile(foreground))
    {
        cout << "Couldn't Load Character Image" << endl;
        exit(1);
    }

    Image backgroundImage;
    backgroundImage = backgroundTex.copyToImage();
    Image foregroundImage;
    foregroundImage = foregroundTex.copyToImage();

    Vector2u sz = backgroundImage.getSize();
    for (int y = 0; y < sz.y; y++)
    {
        for (int x = 0; x < sz.x; x++)
        {
            //these 2 loops will run the code for each pixel in the background image

            Color winterC = backgroundImage.getPixel(x, y); //access current pixel at x,y in the background image
            Color reyC = foregroundImage.getPixel(x, y); //access current pixel at x,y in foreground image

            //RGB values for the green screen are r=16, g=244, and b=22 (found after taking image inot Photoshop)
            //exact values didn't work great, forgot to take shading near character into account
            if ((reyC.r == 32) && (reyC.g == 214) && (reyC.b == 23))
            {
                foregroundImage.setPixel(x, y, winterC);
            }


            //color objects store the individual channel values at like example.g for the green value
        }
    }
    
  
    RenderWindow window(VideoMode(1024, 786), "Here's the output");
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

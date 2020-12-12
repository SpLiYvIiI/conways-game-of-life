#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <ctime>
#include <string>
using namespace std;
using namespace sf;
class dziritadi
{
public:
	dziritadi();
	void adding(const Vector2i & yle);
	void drawingski(RenderWindow & window);
	int counting(int x, int y);
	void updating(float & xui);
	void information(RenderWindow & window);
	void randomfill();
private :
	const int gamravldes = 10;
	int a = 0, b= 0,c=0;
	bool map[500][400];
	sf::RectangleShape rectuk;
	float restartovichi = 0.0f;
	float framespersecond = 0.1f;
};


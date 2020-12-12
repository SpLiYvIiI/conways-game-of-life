#include "dziritadi.h"



dziritadi::dziritadi()
{
	rectuk.setSize(Vector2f(gamravldes, gamravldes));
	rectuk.setFillColor(Color::White);
}

void dziritadi::randomfill() {
	srand(time(NULL));
	for (size_t x(0); x < 400; x++)
		for (size_t y(0); y < 500; y++) {
			map[x][y] = rand() % 2;
		}
}

void dziritadi::adding(const Vector2i & yle) {
	if (yle.x >= 0 && yle.y <= 400 * gamravldes && yle.x  <= 500 * gamravldes && yle.y >= 0) {
		cout << "x : " <<yle.x << " &  " <<"y : " <<yle.y << endl;
		map[int(yle.x)/ gamravldes][int(yle.y) / gamravldes] = true;
	}
}

void dziritadi::drawingski(RenderWindow & window) {
	for (size_t x(0); x < 500; x++)
		for (size_t y(0); y < 400; y++)
			if (map[x][y] == 1) {
				rectuk.setPosition(Vector2f( x * gamravldes, y * gamravldes));
				window.draw(rectuk);

			}
}

int dziritadi::counting(int x, int y) {
	int mtvleli(0);
	for (int a(-1); a <= 1; a++) 
		for (int b(-1); b <= 1; b++) {
			if (a == 0 && b == 0) continue;
			else if (map[x + a][y + b] == 1)
				mtvleli++;
		}
		return mtvleli;
}
void dziritadi::updating(float & xui) {
	restartovichi += xui;
	if (restartovichi >= framespersecond) {
		bool chuchuli[400][500];
		for (size_t x(0); x < 500; x++) {
			for (size_t y(0); y < 400; y++) {
				int count = counting(x, y);
				if (map[x][y] == 1) {
					if (count <= 1 || count > 3) {
					chuchuli[x][y] = 0; a++;
					}
					else if (count >= 2 && count <= 3) { chuchuli[x][y] = 1; c++; }
				}
				else
				{
					if (count == 3) { chuchuli[x][y] = 1; b++; }
				}
			}

		}



		for (size_t x(0); x < 500; x++) {
			std::this_thread::sleep_for(
				std::chrono::nanoseconds(x));
			for (size_t y(0); y < 400; y++) {
				map[x][y] = 0;
				map[x][y] = chuchuli[x][y];
			}
		}
	}
}

void dziritadi::information(RenderWindow & window) {
 string xuila = "Deaths : " + to_string(a) + "   Births : " + to_string(b) + "   Survivors : " + to_string(c);
	Font fontebe;
	Text displaying;
	if (!fontebe.loadFromFile("xuina.otf")) cout << "fonti ver chaitvirta";
	displaying.setFont(fontebe);
	displaying.setString(xuila);
	displaying.setCharacterSize(42);
	window.draw(displaying); 
}

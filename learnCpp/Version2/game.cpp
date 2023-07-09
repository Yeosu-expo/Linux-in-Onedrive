#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <iostream>
#include <vector>

using namespace std;

class GameObject {
	public:
		int x;
		int y;
		virtual void Draw() { }
		virtual bool Update() { return true;}
};

class Player :public GameObject {
	public:
		Player() { x = 10; y = 10;}
		virtual void Draw() {
			move(y,x);
			printw(" ^ ");
			move(y+1,x);
			printw("=-=");
		}
		void KeyboardHandler(int key) {
			switch(key) {
				case 'j': x--; break;
				case 'l': x++; break;
				case 'i': y--; break;
				case 'k': y++; break;
			}
		}
};
class Bomb : public GameObject {
	private:
		int howManyStep;
		int mStep;
	public:
		Bomb() { howManyStep=0; mStep=1;}
		virtual void Draw() {
			if(howManyStep>5){
				int step=howManyStep-5;
				if(step>4){
					move(y,x+(step-mStep));
					printw("*");
					move(y,x-(step-mStep));
					printw("*");
				}
				else{
					move(y, x+step);
					printw("*");
					move(y, x-step);
					printw("*");
				}
			}
			else{
				move(y,x);
				printw("***");
			}
		}
		virtual bool Update() {
			y--;
			howManyStep++;
			if (y < 0) {
				return false;
			}
			return true;
		}
		Missle(Player *player) {
			this->x = player->x;
			this->y = player->y;
		}
};

class Missle : public GameObject {
	public:
		virtual void Draw() {
			move(y,x);
			printw(" ^ ");
		}
		virtual bool Update() {
			y--;
			if (y < 0) {
				return false;
			}
			return true;
		}
		Missle(Player *player) {
			this->x = player->x;
			this->y = player->y;
		}
};

class GameEngine {
	private:
		bool isPlaying;
		Player *player;
		vector<GameObject*> gameObjVec;
		void fire(char type) {
			switch(type){
				case 'b':gameObjVec.push_back(new Bomb(player)); 
				case 'f':gameObjVec.push_back(new Missle(player));
			}
		}

		void DrawGameObject() {
			for(int i = 0 ; i < gameObjVec.size() ; i++)
				gameObjVec[i]->Draw();
		}

		void EngineKeyboardHandler(int key) {
			if(key == 'q')
				isPlaying = false;
			else if (key == 'f')
				fire();
			else if(key=='b')
				fire();
		}

		void UpdateGameObject() {
			for(int i = 0 ; i < gameObjVec.size() ; i++){
				if(gameObjVec[i]->Update() == false) {
					// 여기서 i 번째 미사일을 지운다.
				}
			}
		}

		void HandleKeyboard() {
			int key = getch();
			EngineKeyboardHandler(key);
			player->KeyboardHandler(key);

		}


	public:
		GameEngine() {
			player = new Player();
			gameObjVec.push_back(player);
			isPlaying = true;
		}
		~GameEngine() { delete player; }

		void Run() {
			while(isPlaying) {
				clear();
				UpdateGameObject();
				DrawGameObject();
				HandleKeyboard();
				refresh();
			}
		}
};

class Game {
	GameEngine *engine;
	public:
	Game() { engine = new GameEngine();             }
	~Game() { delete engine; }
	void Run() {
		engine->Run();
	}
};

void game() {
	Game *game = new Game();
	game->Run();
	delete game;
}


void initCurses() {
	initscr();
	curs_set(0);
}

void endCurses() {
	endwin();
}

int main() {
	initCurses();

	game();

	endCurses();
	return 0;
}


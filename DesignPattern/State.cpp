#include <iostream>
#include <string>
using namespace std;

class State{
	public:
		State* getInstance() { return nullptr; };
		virtual void heal() = 0;
		virtual void damage() = 0;
};

class NormalState:public State{
	static NormalState* normalState;
	NormalState() {}
	public:
		static State* getInstance(){
			if(normalState == nullptr)
				normalState = new NormalState();
			return normalState;	
		}
		void heal(){		
			cout << "Player is healed" << endl;
		}
		void damage(){
			cout << "Player get damage" << endl;	
		}
};

NormalState* NormalState::normalState =  nullptr;

class GoodState:public State{
	static GoodState* goodState;
	GoodState() {}
	public:
		static State* getInstance(){
			if(goodState ==  nullptr)
				goodState = new GoodState();
			return goodState;	
		}
		void heal(){
			cout << "Player is too healthy" << endl;	
		}
		void damage(){
			cout << "Player get damage" << endl;	
		}
};

GoodState* GoodState::goodState = nullptr;

class BadState:public State{
	static BadState* badState;
	BadState() {}
	public:
		static State* getInstance(){
			if(badState == nullptr)
				badState = new BadState();
			return badState;	
		}
		void heal(){
			cout << "Player is healed" << endl;	
		}
		void damage(){
			cout << "Player can't get any worse" << endl;	
		}
};

BadState* BadState::badState = nullptr;

class Player{
	State *state;

	public:
		Player(){
			state = NormalState::getInstance();	
		}
		void setState(State *state){
			this->state = state;	
		}
		void playerHeal(){
			state->heal();
			setState(GoodState::getInstance());	
		}
		void playerGetDamege(){
			state->damage();
			setState(BadState::getInstance());	
		}
};

void Client(){
	Player *player = new Player();
	
	player->playerHeal();
	player->playerHeal();
	player->playerGetDamege();
	player->playerGetDamege();
}

int main(){
	Client();

	return 0;
}

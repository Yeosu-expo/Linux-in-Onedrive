#include <iostream>
#include <string>
using namespace std;

class State{
	public:
		State* getInstance() { return nullptr; }
		virtual void heal(State* state) = 0;
		virtual void damage(State* state) = 0;
};

static NormalState* normalState;
static GoodState* goodState;
static BadState* badState;

class NormalState:public State{ 
	public:
	static NormalState* normalState;
	static State* getInstance(){
		if(normalState == nullptr)
			normalState = new NormalState();
		return normalState;	
	}
	void heal(State* state){
		state = GoodState::goodState;	
		cout << "Player is healed" << endl;
	}
	void damage(State* state){
		state = BadState::badState;
		cout << "Player get damage" << endl;	
	}
};

NormalState* NormalState::normalState =  nullptr;

class GoodState:public State{
	GoodState() {}
	public:
	static GoodState* goodState;
	static State* getInstance(){
		if(goodState ==  nullptr)
			goodState = new GoodState();
		return goodState;	
	}
	void heal(State* state){
		cout << "Player is too healthy" << endl;	
	}
	void damage(State* state){
		state = NormalState::normalState;
		cout << "Player get damage" << endl;	
	}
};

GoodState* GoodState::goodState = nullptr;

class BadState:public State{
	BadState() {}
	public:
	static BadState* badState;
	static State* getInstance(){
		if(badState == nullptr)
			badState = new BadState();
		return badState;	
	}
	void heal(State* state){
		state = NormalState::normalState;
		cout << "Player is healed" << endl;	
	}
	void damage(State* state){
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
		state->heal(state);
	}
	void playerGetDamege(){
		state->damage(state);
	}
};

void Client(){
	Player *player = new Player();

	player->playerHeal();
	player->playerHeal();
	player->playerGetDamege();
	player->playerGetDamege();
	player->playerGetDamege();
}

int main(){
	Client();

	return 0;
}

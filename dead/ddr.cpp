//목요드라마 석 & 훈

#include <iostream>

#include <thread>

#include <mutex>

#include <string>

#include <chrono>



using namespace std;



class Actor

{

public:

	string name;

	thread th;

	mutex heart;



	Actor() {}

	virtual void Start(Actor* actor) {}

	virtual void Run(Actor* actor) {}

};





class Hoon : public Actor

{

public:

	void(Hoon::* RunPointer)(Actor* actor);



	Hoon()

	{

		name = "훈이";

	}



	void Start(Actor* actor)

	{

		RunPointer = &Hoon::Run;

		th = thread(RunPointer, this, actor);

		/*th.join();*/



	}



	void Run(Actor* actor) {

		FallinLove(actor);

		Flirting(actor);

		Fuckyou(actor);



	}



	void FallinLove(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "훈 : (나 갑자기..." << actor->name << "을(를) 보니 너무 설렌다....)\n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.lock();

	}



	void Flirting(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "훈 : " << actor->name << "... 내방에서... 라면먹고갈래 ? ? \n\n";



	}



	void Fuckyou(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "훈 : " << actor->name << "... 내방에서... 라면먹고갈래 ? ? \n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.unlock();

	}

};



class Seok : public Actor

{



public:

	void(Seok::* RunPointer)(Actor* actor);



	Seok()

	{

		name = "석이";

	}



	void Start(Actor* actor)

	{

		RunPointer = &Seok::Run;

		th = thread(RunPointer, this, actor);

		/*th.join();*/



	}



	void Run(Actor* actor) {

		FallinLove(actor);

		Flirting(actor);

		Fuckyou(actor);



	}



	void FallinLove(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "훈 : (나 갑자기..." << actor->name << "을(를) 보니 너무 설렌다....)\n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.lock();

	}



	void Flirting(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "훈 : " << actor->name << "... 내방에서... 라면먹고갈래 ? ? \n\n";



	}



	void Fuckyou(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "훈 : " << actor->name << "... 내방에서... 라면먹고갈래 ? ? \n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.unlock();

	}

};



class Su : public Actor

{



public:

	void(Su::* RunPointer)(Actor* actor);



	Su()

	{

		name = "수";

	}



	void Start(Actor* actor)

	{

		RunPointer = &Su::Run;

		th = thread(RunPointer, this, actor);

		/*th.join();*/



	}



	void Run(Actor* actor) {

		FallinLove(actor);

		Flirting(actor);

		Fuckyou(actor);



	}



	void FallinLove(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "훈 : (나 갑자기..." << actor->name << "을(를) 보니 너무 설렌다....)\n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.lock();

	}



	void Flirting(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "훈 : " << actor->name << "... 내방에서... 라면먹고갈래 ? ? \n\n";



	}



	void Fuckyou(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "훈 : " << actor->name << "... 내방에서... 라면먹고갈래 ? ? \n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.unlock();

	}

};



int main() //Thread0 PD : 이은석 (main)

{

	Actor* h = new Hoon();

	Actor* a = new Seok();

	Actor* b = new Su();



	h->Start(h);

	a->Start(a);

	b->Start(b);



	this_thread::sleep_for(std::chrono::milliseconds(1000));

	delete(h);

	delete(a);

	delete(b);



	return 0;

}


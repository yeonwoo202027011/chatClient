//����� �� & ��

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

		name = "����";

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

		cout << "�� : (�� ���ڱ�..." << actor->name << "��(��) ���� �ʹ� ������....)\n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.lock();

	}



	void Flirting(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "�� : " << actor->name << "... ���濡��... ���԰��� ? ? \n\n";



	}



	void Fuckyou(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "�� : " << actor->name << "... ���濡��... ���԰��� ? ? \n\n";

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

		name = "����";

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

		cout << "�� : (�� ���ڱ�..." << actor->name << "��(��) ���� �ʹ� ������....)\n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.lock();

	}



	void Flirting(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "�� : " << actor->name << "... ���濡��... ���԰��� ? ? \n\n";



	}



	void Fuckyou(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "�� : " << actor->name << "... ���濡��... ���԰��� ? ? \n\n";

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

		name = "��";

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

		cout << "�� : (�� ���ڱ�..." << actor->name << "��(��) ���� �ʹ� ������....)\n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.lock();

	}



	void Flirting(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "�� : " << actor->name << "... ���濡��... ���԰��� ? ? \n\n";



	}



	void Fuckyou(Actor* actor)

	{

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "�� : " << actor->name << "... ���濡��... ���԰��� ? ? \n\n";

		this_thread::sleep_for(std::chrono::milliseconds(1000));

		heart.unlock();

	}

};



int main() //Thread0 PD : ������ (main)

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


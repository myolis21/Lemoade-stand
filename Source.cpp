#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
#include <memory>
using namespace std;
class lemonade_stand {
public:
	int money;
	int ing;
	int lem;
	void make() {
		ing--;
		lem++;
	}
	void check() {
		cout << "Current money is:" << money << endl
		<< "Current ingredients is:" << ing << endl 
		<< "Current Lemonade is:" << lem<<endl;
	}
	void sell() {
		money += 2;
		lem--;
	}
	void buy() {
		money--;
		ing++;
	}
	lemonade_stand(int i) : ing(i), money(0), lem(0)
	{
		cout << "stand made"<<endl;
	}
	lemonade_stand(int i, int g) : ing(i), money(g), lem(0) {
		cout << endl << "stand made" << endl;
	}
	~lemonade_stand()
	{
		cout << "stand destroyed"<<endl;
	};
};
int main(){
	int cash;
	vector <lemonade_stand> stands;
	int stdnum(0);
	stands.reserve(15);//allocates uninitialised memory to use later
	stands.emplace_back(10);
	enum action{make, sell, check, buy, makeS};
	string act;
	map <string, action> actions;
	actions.insert(pair<string, action>("make", make));
	actions.insert(pair<string, action>("makeS", makeS));//Make stand
	actions.insert(pair<string, action>("buy", buy));
	actions.insert(pair<string, action>("check", check));
	actions.insert(pair<string, action>("sell", sell));
	while (true) {
		for (int i(0); i < stands.size(); i++) {
			cout << endl << (i+1) << " : ";
			stands[i].check();
			cout << endl;
		}
		
		cout <<"Do one of 5 actions: Make lemonade(make), sell lemonade(sell),"
			<<"buy ingredients(buy),"<<endl<<" or make a new stand(makeS)"<<endl;
		cin >> act;
		if (actions[act] != makeS) {
			cout << "which stand do you want this to apply to?" << endl;
		}
		else {
			cout << "what stand do you wnat to ake cash from?";
		}
		cin >> stdnum;
		switch (actions[act])
		{
		case make:
			stands[stdnum-1].make();
			break;
		case sell:
			stands[stdnum-1].sell();
			break;
		case buy:
			stands[stdnum-1].buy();
			break;
		case makeS:
			cout << endl << "how much money will you transfer?" << endl;
			quickfix:
			cin >> cash;
			if (cash > stands[stdnum].money) {
				cout << endl<<"Not enough cash. Re-enter amount:"<<endl;
				goto quickfix;
			}
			else {
				stands.emplace_back(0, cash);
			}
			break;
		default:
			cout << "someone messed up here and, for god knows what reaon, it"<<endl<<"didnt stop the program";
			break;
		}
	}
}

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

string Card[] = {"0","1","2","3","4","5","6","7","8","9","Skip","+2","Swap","Color","+4"};
string color[] = {" Red"," Bule"," Green"," Yellow"," Black"};
int nCard[] = {4,8,8,8,8,8,8,8,8,8,8,8,8,4,4};
int Deak = 94;

string drawCard();
void showDeak();

int main(){
	srand(time(0));
	string player[99];
	string AI[99];
	string drop;
	int i;
	
	for(i=0;i<7;i++){
		player[i] = drawCard();
		AI[i] = drawCard();
	}
	do{
		drop = drawCard();
	}while(drop == "ColorBlack"||drop == "+4Black");
	cout << drop <<"\n";
	for(i=0;i<7;i++) cout <<"|"<< player[i]<<"| ";
	
	
}

string drawCard(){
	string x,y;
	x = Card[rand()%15];
	if(x == Card[13]||x == Card[14]) return x+color[4];
	else y = color[rand()%4];
	showDeak();
	return x+y;
}

void showDeak(){
	Deak -= 1;
}


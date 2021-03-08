#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>
#include<string.h>

using namespace std;


void playerdrop(string player[],string &CardDrop){
int check=0;
int i;
do{
cin>>i;
char format[]="%d %s";
int numberCard=0,numberCardDrop=0;
char ColorCard[100],ColorCardDrop[100],playerCHAR[]={},CardDropCHAR[]={}; 
strcpy(playerCHAR,player[i].c_str());
strcpy(CardDropCHAR,CardDrop.c_str());
sscanf(playerCHAR,format,&numberCard,ColorCard);
sscanf(CardDropCHAR,format,&numberCardDrop,ColorCardDrop);

cout<<ColorCardDrop;"\n";

	if(numberCard=numberCardDrop){
			CardDrop=player[i];check=1;cout<<"nice";}
	if(ColorCard=ColorCardDrop){
			CardDrop=player[i];check=1;cout<<"nice";}	
	else{
	     	cout<<"try again"<<player[i];}
	
	
}while(check==0);
}




void Aidrop(string sendcard,string &CardDrop){
int check=0;
	CardDrop=sendcard;check=1;
}while(check==0);}



void checkAi(string AICard[],string CardDrop,int n){
char format[]="%d %s";
int numberCard=0,numberCardDrop=0,i=0;
char ColorCard[100],ColorCardDrop[100],AICardchar[]={},CardDropCHAR[]={}; 
string Candrop[]={};
 for(int j=0;j<n;j++){
strcpy(AICardchar, AICard[j].c_str());
strcpy(CardDropCHAR, CardDrop.c_str());

sscanf(AICardchar,format,&numberCard,ColorCard);
sscanf(CardDropCHAR,format,&numberCardDrop,ColorCardDrop);

	if(numberCard==numberCardDrop||ColorCard==ColorCardDrop){
		Candrop[i] = AICard[j]; i++;
	}}
	if(i==0){
		//AICard[] drawcard
	}
else{
	int ci=rand()%i;
 	 string sendcard=Candrop[ci];

	Aidrop(sendcard,CardDrop);
}

}

int main(){
	srand(time(0));
	string player[99]={"2 R","3 G","4 B","0 Y","8 R","5 R"};
	string AI[99]={"8red","6green","6blue","5yellow""1red","7red"};
	string CardDrop;

int i;

CardDrop="8 R";
playerdrop(player,CardDrop);
}
		















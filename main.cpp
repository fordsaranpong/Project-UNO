#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>
#include<string.h>

using namespace std;
string Card[] = {"0","1","2","3","4","5","6","7","8","9","Skip","+2","Swap","Color","+4"};
string color[] = {" Red"," Bule"," Green"," Yellow"," Black"};
int nCard[] = {4,8,8,8,8,8,8,8,8,8,8,8,8,4,4};
int Deak = 94;
string drawCard();
void showDeak();
void playerdrop(string [],int &,string [],string &,int &);
void checkplayer(string [],int &,string [],string &,int &);
void Aidrop(string [],int &,string [],string &,int &);
void checkAi(string [],int &,string [],string &,int &);
void plus2(string [],int &);

int main(){
	srand(time(0));
	string player[99];
	string AICard[99];
	string CardDrop;
	int numplayer,numai,Exit=1;
	int i,j;
	
	for(i=0;i<7;i++){
		player[i] = drawCard();
		AICard[i] = drawCard();
	}
	numplayer=7;numai=7;
	do{
		CardDrop = drawCard();
	}while(CardDrop == "ColorBlack"||CardDrop == "+4Black");
	do{		
	for(j=0;j<numai;j++) cout <<"|"<< AICard[j]<<"| ";	cout <<"\n";
		cout<<"-----------------------------------------------------------------------------\n";
		cout<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<< "\t\t\t\t"<<CardDrop <<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n";
	cout<<"------------------------------------------------------------------------------------------------------\n";	
	for(i=0;i<numplayer;i++) {cout<<i+1 <<".|"<< player[i]<<"| ";}
	cout <<"\n";
//	checkAi(AICard,numai,player,CardDrop,numplayer);
	checkplayer(AICard,numai,player,CardDrop,numplayer);



	system("cls");
	if(numplayer==0||numai==0)Exit=0;

}while(Exit!=0);
    cout<<"WIN";
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
void plus2(string AICard[],int &numai){
    
		AICard[numai] = drawCard();
		numai=numai+1;
		AICard[numai] = drawCard();
		numai=numai+1;
	
}
void plus4(string AICard[],int &numai){
    	
		AICard[numai] = drawCard();
		numai=numai+1;
		AICard[numai] = drawCard();
		numai=numai+1;
		AICard[numai] = drawCard();
		numai=numai+1;
		AICard[numai] = drawCard();
		numai=numai+1;
}
	
	
void checkcardsp(string player[],string &CardDrop,int &numplayer,int i,int &check,string AICard[],int &numai){
		char ColorCard[99],ColorCardDrop[99],playerCHAR[99],CardDropCHAR[99],frontplayer[99],frontcard[99],front4[99]="+4";
		char format[]="%s %s";
		
		strcpy(playerCHAR,player[i].c_str());
		sscanf(playerCHAR,format,frontplayer,ColorCard);
		strcpy(CardDropCHAR,CardDrop.c_str());
		sscanf(CardDropCHAR,format,frontcard,ColorCardDrop);
				if(strcmp(frontplayer,"+4") == 0){
						int x;
						cout<<"Pick Color : 1.RED 2.Blue 3.Green 4.yellow  :";
						cin>>x;
						if(x==1){player[i]="+4 Red";}
						if(x==2){player[i]="+4 Blue";}	
						if(x==3){player[i]="+4 Green";}
						if(x==4){player[i]="+4 Yellow";}
					CardDrop=player[i];
										
					for(int j=i;j<numplayer;j++){
					player[i]=player[i+1];i++;}numplayer--;
					check=1;	    
						plus4(AICard,numai);}
				if(strcmp(frontplayer,"+2") == 0&&(strcmp(frontplayer,frontcard) == 0||strcmp(ColorCard,ColorCardDrop) == 0)){
					CardDrop=player[i];		
					for(int j=i;j<numplayer;j++){
					player[i]=player[i+1];i++;}numplayer--;
					check=1;	    
						plus2(AICard,numai);}
								
				if(strcmp(frontplayer,frontcard) == 0){				
				
					
					
					CardDrop=player[i];
										
					for(int j=i;j<numplayer;j++){
					player[i]=player[i+1];i++;}numplayer--;
					check=1;}	    
				else if(strcmp(ColorCard,ColorCardDrop) == 0){
					
					CardDrop=player[i];check=1;
					for(int j=i;j<numplayer;j++){
					player[i]=player[i+1];i++;}numplayer--;	}	
				else{	cout<<"try again"<<"\n"<<player[i];}						
}


void checkplayer(string AICard[],int &numai,string player[],string &CardDrop,int &numplayer){
		int candrop=0;
		char ColorCard[99],ColorCardDrop[99],playerCHAR[99],CardDropCHAR[99],specialcardplayer[99],specialcarddrop[99],checkblack[99],checkco[99];
		checkblack=="Black";checkco=="Color";
		char format[]="%s %s";
		for(int i=0;i<numplayer;i++){
		strcpy(playerCHAR,player[i].c_str());
		sscanf(playerCHAR,format,specialcardplayer,ColorCard);
		strcpy(CardDropCHAR,CardDrop.c_str());
		sscanf(CardDropCHAR,format,specialcarddrop,ColorCardDrop);
				if(strcmp(specialcardplayer,checkblack) == 0)candrop++;
				if(strcmp(specialcardplayer,specialcarddrop) == 0)candrop++;			   
				if(strcmp(ColorCard,ColorCardDrop) == 0)candrop++;	
				}
		if(candrop==0){player[numplayer] = drawCard();numplayer++;}
		else{ playerdrop(AICard,numai,player,CardDrop,numplayer);} 
			}
				
void playerdrop(string AICard[],int &numai,string player[],string &CardDrop,int &numplayer){
	int check=0;
	int i;
	if(numplayer>0){
		do{
		cout<<"Select Your CARD : ";
		cin>>i;
		i=i-1;
		cout<<player[i]<<"\n";				
		char format[]="%s %s";
		int numberCard=0,numberCardDrop=0;
		char ColorCard[99],ColorCardDrop[99],playerCHAR[99],CardDropCHAR[99],specialcardplayer[99],specialcarddrop[99],checkblack[99],checkco[99];
	
			checkcardsp(player,CardDrop,numplayer,i,check,AICard,numai);
			
		}while(check==0);
	}else{numplayer=0;}


}






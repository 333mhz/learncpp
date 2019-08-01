#include "header.h"
#include "randomMonsterGenerator.h"
#include "cardGame.h"

double dist2(Pnt2d &p1,Pnt2d &p2)
{   return sqrt(pow((p1.m_x - p2.m_x),2)+pow((p1.m_y - p2.m_y),2));    }



int main()
{
	Timer t;

	//srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock

    //rand(); // If using Visual Studio, discard first random value
	
	//Deck deck;

    //deck.prtDeck();

	//deck.shuffleDeck();

	//deck.prtDeck();

	//cout << "1st: " << deck.deal().getCardValue() << endl;
	//cout << "2st: "	<< deck.deal().getCardValue() << endl;

	Blackjack round1;

	if(round1.play())
		cout << "U won!"<<endl;
	else
		cout << "boooo!"<<endl;
	
	
	cout << "Process Time: " << t.elapsed() <<endl;

	return 0;
}
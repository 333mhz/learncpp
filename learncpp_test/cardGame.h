#ifndef CARD_H
#define CARD_H

#include "header.h"

class pokeCard
{
    public:
    enum cSuit
    {
    	SUIT_CLUB,
    	SUIT_DIAMOND,
    	SUIT_HEART,
    	SUIT_SPADE,
		SUIT_JOKE,
		SUIT_JOKER,
    	MAX_SUITS
    };
 
    enum cRank
    {
    	RANK_2,
    	RANK_3,
    	RANK_4,
    	RANK_5,
    	RANK_6,
    	RANK_7,
    	RANK_8,
    	RANK_9,
    	RANK_10,
    	RANK_JACK,
    	RANK_QUEEN,
    	RANK_KING,
    	RANK_ACE,
    	MAX_RANKS
    };
 
    private:
		cSuit suit;
	    cRank rank;

    public:

	pokeCard(cSuit s = MAX_SUITS, cRank r = MAX_RANKS):suit(s), rank(r){}

    void prtCard() const
    {
        switch (suit)
    	{
    		case SUIT_CLUB:		cout << 'C'; break;
    		case SUIT_DIAMOND:	cout << 'D'; break;
    		case SUIT_HEART:	cout << 'H'; break;
    		case SUIT_SPADE:	cout << 'S'; break;
			case SUIT_JOKE:		cout << 'j'; break;
			case SUIT_JOKER:	cout << 'J'; break;
    	}

        switch (rank)	
        {
    		case RANK_2:		cout << '2'; break;
    		case RANK_3:		cout << '3'; break;
    		case RANK_4:		cout << '4'; break;
    		case RANK_5:		cout << '5'; break;
    		case RANK_6:		cout << '6'; break;
    		case RANK_7:		cout << '7'; break;
	    	case RANK_8:		cout << '8'; break;
	    	case RANK_9:		cout << '9'; break;
    		case RANK_10:		cout << 'T'; break;
	    	case RANK_JACK:		cout << 'J'; break;
	    	case RANK_QUEEN:	cout << 'Q'; break;
	    	case RANK_KING:		cout << 'K'; break;
	    	case RANK_ACE:		cout << 'A'; break;
    	}
    }

	int getCardValue() 	const
	{
		switch (rank)
		{
		case RANK_2:		return 2;
		case RANK_3:		return 3;
		case RANK_4:		return 4;
		case RANK_5:		return 5;
		case RANK_6:		return 6;
		case RANK_7:		return 7;
		case RANK_8:		return 8;
		case RANK_9:		return 9;
		case RANK_10:		return 10;
		case RANK_JACK:		return 10;
		case RANK_QUEEN:	return 10;
		case RANK_KING:		return 10;
		case RANK_ACE:		return 11;
		}
		return 0;
	}

};


class Deck
{
	private:
	array<pokeCard, 54> m_deck;
	int m_Idx = 0;
	
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  
		// static used for efficiency, so we only calculate this value once
 		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static void swap(pokeCard &a, pokeCard &b)
	{
 	   	pokeCard temp = a;
		a = b;
		b = temp;
	}
	
	public:

	Deck()
	{
		int i = 0;
		for(int si = 0; si < 4; si++)
		{	
			for(int ri =0; ri < 13; ri++)
			{
				m_deck[i++] = pokeCard(static_cast<pokeCard::cSuit>(si), static_cast<pokeCard::cRank>(ri)); 				
			}
		}	
	}

	void prtDeck() const
    {	
		int i = 0;
         for(const auto &card : m_deck)
         {
             card.prtCard();
			 cout << " ";
			 if((++i)%13 == 0)
			 	cout <<endl;
        }
		cout <<endl;
    }
	
	void shuffleDeck()
	{
		srand(static_cast<unsigned int>(time(0)));
	// Step through each card in the deck
		for (int index = 0; index < 52; ++index)
		{
		// Pick a random card, any card
			int swapIndex = getRandomNumber(0, 51);
		// Swap it with the current card
			swap(m_deck[index], m_deck[swapIndex]);
		}
	}

	const pokeCard& deal()
	{
		assert(m_Idx < 52);
		return m_deck[m_Idx++];
	}
    
};

class Blackjack
{
	private:
	
	Deck deck;

	public:
	Blackjack()
	{
		deck.shuffleDeck();
		deck.prtDeck();

		cout << "Initialized,BlackJack!!!" << endl;
	}

	bool hitOrStand()
	{
		std::cout << "(h) to hit, or (s) to stand: ";
		char choice;
		do
		{
			std::cin >> choice;
		} while (choice != 'h' && choice != 's');

		if(choice == 's')
			return true;
		else
			return false;
	}

	bool play()
	{
		// Set up the initial game state
		const pokeCard *cardPtr = &deck.deal();

		int playerTotal = 0;
		int dealerTotal = 0;
 
		// Deal the dealer one card
		dealerTotal += (*cardPtr++).getCardValue();
		std::cout << "The dealer is showing: " << dealerTotal << '\n';
 
		// Deal the player two cards
		playerTotal += (*cardPtr++).getCardValue();
		playerTotal += (*cardPtr++).getCardValue();
 
		// Player goes first
		while (1)
		{
			std::cout << "You have: " << playerTotal << '\n';
			if (hitOrStand())
				break;
 
			playerTotal += (*cardPtr++).getCardValue();
		
			// See if the player busted
			if (playerTotal > 21)
				return false;
		}
 
		// If player hasn't busted, dealer goes until he has at least 17 points
		while (dealerTotal < 17)
		{
			dealerTotal += (*cardPtr++).getCardValue();
			std::cout << "The dealer now has: " << dealerTotal << '\n';
		}
 
		// If dealer busted, player wins
		if (dealerTotal > 21)
			return true;
 
		return (playerTotal > dealerTotal);
		}

};

void playBlackjack()
{
	int r = 0;
	while(true)
	{
		assert (r < 3);
		Blackjack round;
		cout << "Round" << ++r << endl;

		if(round.play())
			cout << "U won!"<<endl;
		else
			cout << "boooo!"<<endl;

		char again;
		cout<<"Again?(Enter a again)"<<endl;
		cin >> again;
		if(again != 'a')
			break;
	}
}

#endif
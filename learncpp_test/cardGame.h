#ifndef CARD_H
#define CARD_H

#include "header.h"

class poke
{
    public:
    enum cSuit
    {
    	SUIT_CLUB,
    	SUIT_DIAMOND,
    	SUIT_HEART,
    	SUIT_SPADE,
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
 
    struct Card
    {
	    cRank rank;
	    cSuit suit;
    };

    private:
        array<Card, 52> deck;

    public:

    void prtCard() const
    {
        switch (deck.suit)
    	{
    		case SUIT_CLUB:		cout << 'C'; break;
    		case SUIT_DIAMOND:	cout << 'D'; break;
    		case SUIT_HEART:	cout << 'H'; break;
    		case SUIT_SPADE:	cout << 'S'; break;
    	}

        switch (deck.rank)	
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

    void prtDeck() const
    {
        for(const auto &card : deck)
        {
            card.prtCard();
            cout << " ";
        }
    }

    void swap(Card &tg)
    {
        Card temp = 
    }
    
};

#endif
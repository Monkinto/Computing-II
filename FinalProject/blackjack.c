#include "blackjack.h"

void swapStrings(char one[], char two[]){
	char temp[MAXSTRINGSIZE];
	char temp2[MAXSTRINGSIZE];
	strcpy(temp, one);
	strcpy(temp2, two);
	strcpy(two, temp);
	strcpy(one, temp2);
}

void shuffleDeck(deckPtr theDeck){
	char cardNames[52][MAXSTRINGSIZE] = {
		{"Ace of Hearts"}, {"Ace of Spades"}, {"Ace of Diamonds"}, {"Ace of Clubs"},
		{"Two of Hearts"}, {"Two of Spades"}, {"Two of Diamonds"}, {"Two of Clubs"},
		{"Three of Hearts"}, {"Three of Spades"}, {"Three of Diamonds"}, {"Three of Clubs"},
		{"Four of Hearts"}, {"Four of Spades"}, {"Four of Diamonds"}, {"Four of Clubs"},
		{"Five of Hearts"}, {"Five of Spades"}, {"Five of Diamonds"}, {"Five of Clubs"},
		{"Six of Hearts"}, {"Six of Spades"}, {"Six of Diamonds"}, {"Six of Clubs"},
		{"Seven of Hearts"}, {"Seven of Spades"}, {"Seven of Diamonds"}, {"Seven of Clubs"},
		{"Eight of Hearts"}, {"Eight of Spades"}, {"Eight of Diamonds"}, {"Eight of Clubs"},
		{"Nine of Hearts"}, {"Nine of Spades"}, {"Nine of Diamonds"}, {"Nine of Clubs"},
		{"Ten of Hearts"}, {"Ten of Spades"}, {"Ten of Diamonds"}, {"Ten of Clubs"},
		{"Jack of Hearts"}, {"Jack of Spades"}, {"Jack of Diamonds"}, {"Jack of Clubs"},
		{"Queen of Hearts"}, {"Queen of Spades"}, {"Queen of Diamonds"}, {"Queen of Clubs"},
		{"King of Hearts"}, {"King of Spades"}, {"King of Diamonds"}, {"King of Clubs"}
	};
	int randNum, i;
	emptyDeck(theDeck);
	for(i = 51; i >= 0; i--){
		randNum = rand()%51;
		swapStrings(cardNames[i], cardNames[randNum]);
	}
	for(i = 0; i < 52; i++){
		addCardDeck(theDeck, cardNames[i], 0);
	}
}

int main(int argc, char const *argv[]){
	playerListPtr testPlayer = initPlayerList();
	addPlayer(testPlayer, 0);
	deckPtr testDeck = initDeck();
	cardPtr tempCard;
	srand(time(NULL));
	shuffleDeck(testDeck);
	while(isDeckEmpty(testDeck) == 1){
		tempCard = checkCardDeck(testDeck);
		printf("%s\n", tempCard->theName);
		removeCardDeck(testDeck);
	}
	return 0;
}
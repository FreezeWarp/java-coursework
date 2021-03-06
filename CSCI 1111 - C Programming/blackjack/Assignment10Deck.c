int deckPosition;


/**
 * Generate's a sequential deck array. If cards > 52, will create multiple sequential decks.
 * If CARDS_TOTAL % CARDS_PER_DECK != 0, then the cards used will be predictable (first aces, twos, up to kings, and first hearts, then diamonds, clubs, and then spades), and will not be random.
 */
void populateDeck(DeckArray deck) {
    int i;

    for (i = 0; i < CARDS_TOTAL; i++)
        deck[i] = i % CARDS_PER_DECK;
}



/**
 * Randomises an already populated deck.
 * Shuffle repetitions is basically arbitrary, though matching CARDS_TOTAL is likely perfectly random. I would omit it entirely, but I feel it better simulates real life, which could be fun in some circumstances.
 */
void shuffleDeck(DeckArray deck, int repetitions) {
    int i, pickACard, thisCard;
    static bool shuffled = false;
    
    deckPosition = 0; // Reset deck position.
    
    if (!shuffled) { // Since multiple calls can be made to shuffle deck, make sure we only seed once.
        srand(time(NULL));
        shuffled = true;
    }

    for (i = 0; i < repetitions; i++) {
        pickACard = rand() % CARDS_TOTAL;

        thisCard = deck[i % CARDS_TOTAL];
        deck[i % CARDS_TOTAL] = deck[pickACard];
        deck[pickACard] = thisCard;
    }
}



/**
 * "Deals" a card by returning the lowest unused card in the deck stack.
 */
int dealCard(DeckArray deck) {
    if (deckPosition >= CARDS_TOTAL) { // If the current deck position is out-of-bounds, shuffle the deck (which resets its position to 0).
        shuffleDeck(deck, CARDS_TOTAL);
        deckPosition = 0;
    }

    return deck[deckPosition++]; // Set deck position to current deck position plus one, then return previous deck position as the dealt card's value.
}


void countCards(DeckArray deck) {
    int i;
    int count[11] = {0};
    
    for (i = deckPosition; i < CARDS_PER_DECK; i++) {
        count[getCardValue(deck[i]) - 2]++;
    }
    
    for (i = 2; i < 12; i++) {
        printf("%d//%d  ", i, count[i - 2]);
    }
    printf("\n");
}

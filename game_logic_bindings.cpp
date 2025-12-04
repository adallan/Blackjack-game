# include <iomanip>
# include <iostream>
# include <string>
# include <vector>
# include <random>
# include <algorithm>
# include <emscripten/bind.h>

using namespace emscripten;

// enumeration for suits
enum class Suit {
    Hearts,
    Diamonds,
    Spades,
    Clubs
};

//enumeration for ranks of cards
enum class Rank {
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack, Queen, King, Ace
};

// Card class and creation of cards
class Card 
{
private:
    Suit suit;
    Rank rank;
    
public:
    // Card constructor
    Card (Suit s, Rank r) : suit(s), rank(r) {}

    int get_value() const {
        switch(rank) {
            case Rank::Two:
                return 2;
            case Rank::Three:
                return 3;
            case Rank::Four:
                return 4;
            case Rank::Five:
                return 5;
            case Rank::Six:
                return 6;
            case Rank::Seven:
                return 7;
            case Rank::Eight:
                return 8;
            case Rank::Nine:
                return 9;
            case Rank::Ten:
            case Rank::Jack:
            case Rank::Queen:
            case Rank::King:
                return 10;
            case Rank::Ace:
                return 11; //Will adjust to 1 when needed
        }
        return 0;
    }
    std::string to_string() const {
        std::string rankStr;
        std::string suitStr;

        switch(rank) {
            case Rank::Two:
                rankStr = "Two";
                break;
            case Rank::Three:
                rankStr = "Three";
                break;
            case Rank::Four:
                rankStr = "Four";
                break;
            case Rank::Five:
                rankStr = "Five";
                break;
            case Rank::Six:
                rankStr = "Six";
                break;
            case Rank::Seven:
                rankStr = "Seven";
                break;
            case Rank::Eight:
                rankStr = "Eight";
                break;
            case Rank::Nine:
                rankStr = "Nine";
                break;
            case Rank::Ten:
                rankStr = "Ten";
                break;
            case Rank::Jack:
                rankStr = "Jack";
                break;
            case Rank::Queen:
                rankStr = "Queen";
                break;
            case Rank::King:
                rankStr = "King";
                break;
            case Rank::Ace:
                rankStr = "Ace";
                break;
        }
        switch(suit) {
            case Suit::Hearts:
                suitStr = "Hearts";
                break;
            case Suit::Diamonds:
                suitStr = "Diamonds";
                break;
            case Suit::Spades:
                suitStr = "Spades";
                break;
            case Suit::Clubs:
                suitStr = "Clubs";
                break;
        }
        return rankStr + " of " + suitStr;
    }
};

class Deck {
private:
    std::vector<Card> card_deck;

public:
    // Deck constructor
    void new_deck ()
    {
        card_deck.clear();
        for ( int s=0; s<4; s++)
        {
            for (int r=0; r<13; r++)
            {
                Suit suit = static_cast<Suit>(s);
                Rank rank = static_cast<Rank>(r);

                Card new_card(suit,rank);
                card_deck.push_back(new_card);
            }
        }
    }
    void shuffle ()
    {
        std::random_device rd;
        std::mt19937 rng(rd());

        std::shuffle(card_deck.begin(), card_deck.end(), rng);
    }
    Card deal_card()
    {
        if (card_deck.size() == 0)
        {
            new_deck();
        }
        Card dealt_card = card_deck.back();
        card_deck.pop_back();
        return dealt_card;
    }
};

class Player {

private:
    int chips;
    std::vector<Card> hand;

public:
    Player(int starting_chips) : chips(starting_chips)
    {
        hand.clear();
    }
    void add_card(Card new_card)
    {
        hand.push_back(new_card);
    }
    int get_hand_value()
    {
        int total = 0;
        int ace_count = 0;
        for (size_t c=0; c< hand.size(); c++)
            {
                total += hand[c].get_value();
                if (hand[c].get_value() == 11)
                {
                    ace_count += 1;
                }
            }
        while (total > 21 && ace_count > 0)
        {
            total -= 10; // turn one or more aces into 1s
            ace_count--;
        }
        return total;
    }
    std::string get_hand_string()
    {
        std::string result;
        for (const Card& c : hand)
        {
            result += c.to_string();
            result += "\n";
        }
        return result;
    }
    void clear_hand()
    {
        hand.clear();
    }
    int place_bet(int amount)
    {
        if (amount > chips)
        {
            return 0; 
            //cannot place a bet 0 will be used in Javascript to see if failed to bet
        }
        chips -= amount;
        return amount;
    }
    void add_chips(int amount)
    {
        chips += amount; 
    }
    int show_chips()
    {
        return chips;
    }
};
class Dealer {

private:
    std::vector<Card> hand;

public:
    Dealer() {} //dealer constructor

    void add_card(Card new_card)
    {
        hand.push_back(new_card);
    }

    int get_hand_value()
    {
        int total = 0;
        int ace_count = 0;
        for (size_t c=0; c< hand.size(); c++)
            {
                total += hand[c].get_value();
                if (hand[c].get_value() == 11)
                {
                    ace_count += 1;
                }
            }
        while (total > 21 && ace_count > 0)
        {
            total -= 10; // turn one or more aces into 1s
            ace_count--;
        }
        return total;
    }
    std::string get_hand_string()
    {
        std::string result;
        for (const Card& c : hand)
        {
            result += c.to_string();
            result += "\n";
        }
        return result;
    }
    void clear_hand()
    {
        hand.clear();
    }
};
enum class hand_results {PlayerWins, DealerWins, Tie, None};

hand_results check_winner(Player& player, Dealer& dealer)
{
    int player_total = player.get_hand_value();
    int dealer_total = dealer.get_hand_value();

    if (player_total > 21 && dealer_total > 21)
    {
        return hand_results::Tie;
    }
    if (player_total > 21 )
    {
        return hand_results::DealerWins;
    }
    if (dealer_total > 21)
    {
        return hand_results::PlayerWins;
    }
    if (player_total > dealer_total)
    {
        return hand_results::PlayerWins;
    }
    if (player_total < dealer_total)
    {
        return hand_results::DealerWins;
    }
    else
    {
        return hand_results::Tie;
    }
}
//Non-class specific Functions
bool bust_check_player(Player& player)
{
    return player.get_hand_value() > 21;
}
bool bust_check_dealer(Dealer& dealer)
{
    return dealer.get_hand_value() > 21;
}
void hit_card(Player& player, Deck& deck)
{
    player.add_card(deck.deal_card());
}
void starting_hands(Player& player, Deck& deck, Dealer& dealer)
{
    deck.new_deck();
    deck.shuffle();
    player.add_card(deck.deal_card());
    dealer.add_card(deck.deal_card());
    player.add_card(deck.deal_card());
    dealer.add_card(deck.deal_card());
}

//Emscripten bindings for JavaScript handling
EMSCRIPTEN_BINDINGS(blackjack_module) 
{
    //Enum bindings for card construction
    enum_<Suit>("Suit")
        .value("HEARTS", Suit::Hearts)
        .value("DIAMONDS", Suit::Diamonds)
        .value("CLUBS", Suit::Clubs)
        .value("SPADES", Suit::Spades);

    enum_<Rank>("Rank")
        .value("ACE", Rank::Ace)
        .value("TWO", Rank::Two)
        .value("THREE", Rank::Three)
        .value("FOUR", Rank::Four)
        .value("FIVE", Rank::Five)
        .value("SIX", Rank::Six)
        .value("SEVEN", Rank::Seven)
        .value("EIGHT", Rank::Eight)
        .value("NINE", Rank::Nine)
        .value("TEN", Rank::Ten)
        .value("JACK", Rank::Jack)
        .value("QUEEN", Rank::Queen)
        .value("KING", Rank::King);
        
//Card bindings
    class_<Card>("Card")
        .constructor<Suit, Rank>()
        .function("to_string", &Card::to_string)
        .function("get_value", &Card::get_value);

//Deck bindings
    class_<Deck>("Deck")
        .constructor<>()
        .function("new_deck", &Deck::new_deck)
        .function("shuffle", &Deck::shuffle)
        .function("deal_card", &Deck::deal_card);

//Player bindings
    class_<Player>("Player")
        .constructor<int>()
        .function("add_card", &Player::add_card)
        .function("get_hand_value", &Player::get_hand_value)
        .function("get_hand_string", &Player::get_hand_string)
        .function("place_bet", &Player::place_bet)
        .function("add_chips", &Player::add_chips)
        .function("show_chips", &Player::show_chips);

//Dealer bindings
    class_<Dealer>("Dealer")
        .constructor<>()
        .function("add_card", &Dealer::add_card)
        .function("get_hand_value", &Dealer::get_hand_value)
        .function("get_hand_string", &Dealer::get_hand_string);

//Game functions
    function("starting_hands", &starting_hands);
    function("hit_card", &hit_card);
    function("bust_check_player", &bust_check_player);
    function("bust_check_dealer", &bust_check_dealer);

enum_<hand_results>("hand_results")
        .value("PlayerWins", hand_results::PlayerWins)
        .value("DealerWins", hand_results::DealerWins)
        .value("Tie", hand_results::Tie)
        .value("None", hand_results::None);
}

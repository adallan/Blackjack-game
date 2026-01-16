# include <iomanip>
# include <iostream>
# include <string>
# include <vector>
# include <random>
# include <algorithm>

using namespace std;

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
    void print_hand()
    {
        std::cout << "Player's hand: \n";
        for (const Card& c : hand)
        {
            std::cout << c.to_string() << "\n";
        }
    }
    void clear_hand()
    {
        hand.clear();
    }
    int place_bet(int amount)
    {
        if (amount > chips)
        {
            std::cout << "You don't have enough chips!\n";
            return chips;
        }
        chips -= amount;
        return amount;
    }
    void add_chips(int amount)
    {
        chips += amount; 
    }
    void show_chips()
    {
        std::cout << "You have " << chips << " chips left" <<"\n";
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
    void print_hand()
    {
        std::cout << "Dealer's hand: \n";
        for (const Card& c : hand)
        {
            std::cout << c.to_string() << "\n";
        }
    }
    void clear_hand()
    {
        hand.clear();
    }
};
void bust_check(Player& player)
{
    if (player.get_hand_value() > 21)
    {
        cout << "You bust! Dealer wins this hand." << "\n";
        player.print_hand();
        cout << player.get_hand_value() << "\n";
    }
    else
    {
        player.print_hand();
        cout << player.get_hand_value() << "\n";
    }
}
void hit_or_stay(Player& player, Deck& deck)
{
    char loop_sentinel = 'Y';
    string answer;
    while (loop_sentinel=='Y')
    {
        if (player.get_hand_value() > 21)
        {
            loop_sentinel = 'N';
        }
        else
        {
            cout << "Do you want to hit or stay? ";
            cin >> answer;
            if (answer == "hit" || answer == "Hit")
            {
                player.add_card(deck.deal_card());
                bust_check(player);
            }
            else
            {
                loop_sentinel = 'N';
            }
        }
    }
}
void winner_check(Player& player, Dealer& dealer, int prize)
{
    int player_total = player.get_hand_value();
    int dealer_total = dealer.get_hand_value();

    if (player_total > 21 && dealer_total > 21)
    {
        cout << "Both the player and dealer both bust! It's a tie. \n";
        player.add_chips(prize);
    }
    else if (player_total > 21)
    {
        cout << "You busts! Dealer wins. \n";
    }
    else if (dealer_total > 21)
    {
        cout << "Dealer busts! You win! \n";
        player.add_chips(prize*2);
    }
    else if (player_total > dealer_total)
    {
        cout << "You have: " << player_total << "\n";
        cout << "Deal has: " << dealer_total << "\n";
        cout << "You win! \n";
        player.add_chips(prize*2);
    }
    else if (player_total < dealer_total)
    {
        cout << "You have: " << player_total << "\n";
        cout << "Deal has: " << dealer_total << "\n";
        cout << "You lose! \n";
    }
    else
    {
        cout << "You have: " << player_total << "\n";
        cout << "Deal has: " << dealer_total << "\n";
        cout << "Its a tie! \n";
        player.add_chips(prize);
    }
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
void dealer_turn(Dealer& dealer, Deck& deck)
{
    while (dealer.get_hand_value() < 17)
    {
        cout << "Dealer hits another card \n";
        dealer.add_card(deck.deal_card());
        if (dealer.get_hand_value() > 21)
        {
            dealer.print_hand();
            cout << dealer.get_hand_value() << "\n";
            return;
        }
    }
    if (dealer.get_hand_value() >= 17)
    {
        cout << "Dealer stays. \n";
        dealer.print_hand();
        cout << dealer.get_hand_value() << "\n";
    }
}
void game_on()
{
    Deck deck;
    Player player1(20);
    Dealer dealer;
    int prize_pool = 0;
    int bet_increase = 0;
    char bet = 'N';
    char play_again = 'N';
    bool game_loop = true;

    while (game_loop == true)
    {
        cout << "Each hand is 5 chips" << "\n";
        prize_pool = player1.place_bet(5);
        starting_hands(player1, deck, dealer);
        player1.print_hand();
        cout << player1.get_hand_value() << "\n";
        dealer.print_hand();
        cout << dealer.get_hand_value() << "\n";
        player1.show_chips();
        cout << "Would you like to increase you bet? (Y/N) \n";
        cin >> bet;
        if (bet == 'Y' || bet == 'y')
        {
            cout << "How much would you like to bet? \n";
            cin >> bet_increase;
            prize_pool += player1.place_bet(bet_increase); 
        }
        hit_or_stay(player1, deck);
        dealer_turn(dealer, deck);
        winner_check(player1, dealer, prize_pool);
        player1.show_chips();
        cout << "Do you want to play another hand? (Y/N) \n";
        cin >> play_again;
        if (play_again != 'Y' && play_again != 'y')
        {
            game_loop = false;
        }
        player1.clear_hand();
        dealer.clear_hand();
    }
}
int main() 
{
    game_on();
    return 0;
}
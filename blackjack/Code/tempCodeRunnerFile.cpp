# include <iomanip>
# include <iostream>
# include <string>

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
                return 1; //Will adjust to 11 when needed
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
        return rankStr + "of" + suitStr;
    }
};

int main() {
    Card c(Suit::Spades, Rank::Ace);

    std::cout << "Card" << c.to_string() << "\n";
    std::cout << "value" << c.get_value() << "\n";

    return 0;
}
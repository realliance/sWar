#include "card.h"

#include <map>
#include <string>

using sWar::Card;

auto Card::toUint8_t() const -> uint8_t {
  return c;
}

auto Card::getSuit() const -> uint8_t {
  return c & 3u << 5;
}

auto Card::getCardNum() const -> uint8_t {
  return c & 15u;
}

const std::map<uint8_t, std::string> STR_MAP = {
  {Card::ERROR, "INVALID CARD"},
  {Card::ACE_OF_CLUBS, "ACE OF CLUBS"},
  {Card::TWO_OF_CLUBS, "TWO OF CLUBS"},
  {Card::THREE_OF_CLUBS, "THREE OF CLUBS"},
  {Card::FOUR_OF_CLUBS, "FOUR OF CLUBS"},
  {Card::FIVE_OF_CLUBS, "FIVE OF CLUBS"},
  {Card::SIX_OF_CLUBS, "SIX OF CLUBS"},
  {Card::SEVEN_OF_CLUBS, "SEVEN OF CLUBS"},
  {Card::EIGHT_OF_CLUBS, "EIGHT OF CLUBS"},
  {Card::NINE_OF_CLUBS, "NINE OF CLUBS"},
  {Card::TEN_OF_CLUBS, "TEN OF CLUBS"},
  {Card::JACK_OF_CLUBS, "JACK OF CLUBS"},
  {Card::QUEEN_OF_CLUBS, "QUEEN OF CLUBS"},
  {Card::KING_OF_CLUBS, "KING OF CLUBS"},

  {Card::ACE_OF_DIAMONDS, "ACE OF DIAMONDS"},
  {Card::TWO_OF_DIAMONDS, "TWO OF DIAMONDS"},
  {Card::THREE_OF_DIAMONDS, "THREE OF DIAMONDS"},
  {Card::FOUR_OF_DIAMONDS, "FOUR OF DIAMONDS"},
  {Card::FIVE_OF_DIAMONDS, "FIVE OF DIAMONDS"},
  {Card::SIX_OF_DIAMONDS, "SIX OF DIAMONDS"},
  {Card::SEVEN_OF_DIAMONDS, "SEVEN OF DIAMONDS"},
  {Card::EIGHT_OF_DIAMONDS, "EIGHT OF DIAMONDS"},
  {Card::NINE_OF_DIAMONDS, "NINE OF DIAMONDS"},
  {Card::TEN_OF_DIAMONDS, "TEN OF DIAMONDS"},
  {Card::JACK_OF_DIAMONDS, "JACK OF DIAMONDS"},
  {Card::QUEEN_OF_DIAMONDS, "QUEEN OF DIAMONDS"},
  {Card::KING_OF_DIAMONDS, "KING OF DIAMONDS"},

  {Card::ACE_OF_SPADES, "ACE OF SPADES"},
  {Card::TWO_OF_SPADES, "TWO OF SPADES"},
  {Card::THREE_OF_SPADES, "THREE OF SPADES"},
  {Card::FOUR_OF_SPADES, "FOUR OF SPADES"},
  {Card::FIVE_OF_SPADES, "FIVE OF SPADES"},
  {Card::SIX_OF_SPADES, "SIX OF SPADES"},
  {Card::SEVEN_OF_SPADES, "SEVEN OF SPADES"},
  {Card::EIGHT_OF_SPADES, "EIGHT OF SPADES"},
  {Card::NINE_OF_SPADES, "NINE OF SPADES"},
  {Card::TEN_OF_SPADES, "TEN OF SPADES"},
  {Card::JACK_OF_SPADES, "JACK OF SPADES"},
  {Card::QUEEN_OF_SPADES, "QUEEN OF SPADES"},
  {Card::KING_OF_SPADES, "KING OF SPADES"},

  {Card::ACE_OF_HEARTS, "ACE OF HEARTS"},
  {Card::TWO_OF_HEARTS, "TWO OF HEARTS"},
  {Card::THREE_OF_HEARTS, "THREE OF HEARTS"},
  {Card::FOUR_OF_HEARTS, "FOUR OF HEARTS"},
  {Card::FIVE_OF_HEARTS, "FIVE OF HEARTS"},
  {Card::SIX_OF_HEARTS, "SIX OF HEARTS"},
  {Card::SEVEN_OF_HEARTS, "SEVEN OF HEARTS"},
  {Card::EIGHT_OF_HEARTS, "EIGHT OF HEARTS"},
  {Card::NINE_OF_HEARTS, "NINE OF HEARTS"},
  {Card::TEN_OF_HEARTS, "TEN OF HEARTS"},
  {Card::JACK_OF_HEARTS, "JACK OF HEARTS"},
  {Card::QUEEN_OF_HEARTS, "QUEEN OF HEARTS"},
  {Card::KING_OF_HEARTS, "KING OF HEARTS"}};

auto Card::toStr() const -> std::string {
  if (STR_MAP.contains(c)) {
    return STR_MAP.at(c);
  }
  return STR_MAP.at(Card::ERROR);
}

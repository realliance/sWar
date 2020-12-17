#pragma once
#include <cstdint>
#include <string>

namespace sWar {

class Card {
 public:
  explicit Card(uint8_t c) : c(c) {}

  // LSB aligned
  // SUIT_2, ACE_1, PIECE_4
  enum Type : std::uint8_t {
    CLUB = 0 << 5,
    DIAMOND = 1 << 5,
    SPADE = 2 << 5,
    HEART = 3 << 5,

    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14,

    ERROR = 0,

    TWO_OF_CLUBS = CLUB | 2u,
    THREE_OF_CLUBS = CLUB | 3u,
    FOUR_OF_CLUBS = CLUB | 4u,
    FIVE_OF_CLUBS = CLUB | 5u,
    SIX_OF_CLUBS = CLUB | 6u,
    SEVEN_OF_CLUBS = CLUB | 7u,
    EIGHT_OF_CLUBS = CLUB | 8u,
    NINE_OF_CLUBS = CLUB | 9u,
    TEN_OF_CLUBS = CLUB | 10u,
    JACK_OF_CLUBS = CLUB | JACK,
    QUEEN_OF_CLUBS = CLUB | QUEEN,
    KING_OF_CLUBS = CLUB | KING,
    ACE_OF_CLUBS = CLUB | ACE,

    TWO_OF_DIAMONDS = DIAMOND | 2u,
    THREE_OF_DIAMONDS = DIAMOND | 3u,
    FOUR_OF_DIAMONDS = DIAMOND | 4u,
    FIVE_OF_DIAMONDS = DIAMOND | 5u,
    SIX_OF_DIAMONDS = DIAMOND | 6u,
    SEVEN_OF_DIAMONDS = DIAMOND | 7u,
    EIGHT_OF_DIAMONDS = DIAMOND | 8u,
    NINE_OF_DIAMONDS = DIAMOND | 9u,
    TEN_OF_DIAMONDS = DIAMOND | 10u,
    JACK_OF_DIAMONDS = DIAMOND | JACK,
    QUEEN_OF_DIAMONDS = DIAMOND | QUEEN,
    KING_OF_DIAMONDS = DIAMOND | KING,
    ACE_OF_DIAMONDS = DIAMOND | ACE,

    TWO_OF_SPADES = SPADE | 2u,
    THREE_OF_SPADES = SPADE | 3u,
    FOUR_OF_SPADES = SPADE | 4u,
    FIVE_OF_SPADES = SPADE | 5u,
    SIX_OF_SPADES = SPADE | 6u,
    SEVEN_OF_SPADES = SPADE | 7u,
    EIGHT_OF_SPADES = SPADE | 8u,
    NINE_OF_SPADES = SPADE | 9u,
    TEN_OF_SPADES = SPADE | 10u,
    JACK_OF_SPADES = SPADE | JACK,
    QUEEN_OF_SPADES = SPADE | QUEEN,
    KING_OF_SPADES = SPADE | KING,
    ACE_OF_SPADES = SPADE | ACE,

    TWO_OF_HEARTS = HEART | 2u,
    THREE_OF_HEARTS = HEART | 3u,
    FOUR_OF_HEARTS = HEART | 4u,
    FIVE_OF_HEARTS = HEART | 5u,
    SIX_OF_HEARTS = HEART | 6u,
    SEVEN_OF_HEARTS = HEART | 7u,
    EIGHT_OF_HEARTS = HEART | 8u,
    NINE_OF_HEARTS = HEART | 9u,
    TEN_OF_HEARTS = HEART | 10u,
    JACK_OF_HEARTS = HEART | JACK,
    QUEEN_OF_HEARTS = HEART | QUEEN,
    KING_OF_HEARTS = HEART | KING,
    ACE_OF_HEARTS = HEART | ACE
  };
  static const int PIECESIZE = 256;

  [[nodiscard]] auto toUint8_t() const -> uint8_t;
  [[nodiscard]] auto getSuit() const -> uint8_t;
  [[nodiscard]] auto getCardNum() const -> uint8_t;
  [[nodiscard]] auto toStr() const -> std::string;

  inline auto operator++() -> Card& {
    if (getCardNum() > QUEEN) {
      c = ERROR;
      return *this;
    }
    c = c + 1;
    return *this;
  }

  inline auto operator==(const Card rhs) const -> bool {
    return c == rhs.c;
  }

  inline auto operator!=(const Card rhs) const -> bool {
    return c != rhs.c;
  }

  inline auto operator-(uint8_t i) const -> Card {
    if (i == 0) {
      return Card(c);
    }
    if (getCardNum() < i || getCardNum() - i < 1) {
      return Card{ERROR};
    }
    uint8_t card = getSuit() | getCardNum();
    if (getCardNum() - i == 1) {
      card |= ACE;
    }
    return Card(card);
  }

  inline auto operator+(uint8_t i) const -> Card {
    if (i == 0) {
      return Card(c);
    }
    if (getCardNum() + i > KING) {
      return Card{ERROR};
    }
    return Card(getSuit() | getCardNum());
  }

  inline auto operator<(Card other) const -> bool {
    if (getSuit() != other.getSuit()) {
      return getSuit() > other.getSuit();
    }
    return getCardNum() < other.getCardNum();
  };

 private:
  uint8_t c{ERROR};
};
}  // namespace sWar

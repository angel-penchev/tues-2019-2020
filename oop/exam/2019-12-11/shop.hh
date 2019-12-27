#ifndef SHOP_HH
#define SHOP_HH

#include <string>
#include <vector>
#include "acoustic.hh"
#include "electric.hh"

class Shop {
  std::vector<Acoustic> acoustic;
  std::vector<Electric> electric;

public:
  class ErrorNoneFound {};
  Shop(std::vector<Acoustic> acoustic, std::vector<Electric> electric);

  std::vector<Guitar> get_all_in_price_range(double from_price, double to_price) const;

  std::vector<Acoustic> get_all_twelve_strings() const;

  Acoustic const& get_most_powerful_acoustic();

  Electric const& get_most_powerful_electric();

  void add_accoustic(Acoustic const& acoustic);

  void add_electric(Electric const& electric);

  void buy(Guitar const& guitar);

};

#endif

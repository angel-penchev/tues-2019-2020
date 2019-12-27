#ifndef INSTRUMENT_HH
#define INSTRUMENT_HH

#include <string>

class Instrument {
  unsigned int id;
  double price;
  std::string brand;

public:
  Instrument(unsigned int id, double price, std::string brand);

  unsigned int getId() const;

  double getPrice() const;

  std::string getBrand() const;
};

#endif

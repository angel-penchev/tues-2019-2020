#ifndef GUITAR_HH
#define GUITAR_HH

#include "instrument.hh"

class Guitar : public Instrument {
  unsigned int strings;
  unsigned int frets;
  double weigth;

public:
  Guitar(unsigned int id, double price, std::string brand, unsigned int strings, unsigned int frets, double weigth);

  unsigned int getStrings() const;

  unsigned int getFrets() const;

  double getWeigth() const;
};

#endif

#ifndef ACOUSTIC_HH
#define ACOUSTIC_HH

#include <string>
#include "guitar.hh"

class Acoustic : public Guitar {
  double output;

public:
  Acoustic();

  Acoustic(unsigned int id, double price, std::string brand, unsigned int strings, unsigned int frets, double weigth, double output);

  double getOutput() const;

  Acoustic& operator=(Acoustic const& other);
};

#endif

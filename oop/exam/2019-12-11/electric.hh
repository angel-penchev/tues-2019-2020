#ifndef ELECTRIC_HH
#define ELECTRIC_HH

#include <string>
#include "guitar.hh"

class Electric : public Guitar {
  unsigned int pickups;
  double pickups_output;

public:
  Electric();
  
  Electric(unsigned int id, double price, std::string brand, unsigned int strings, unsigned int frets, double weigth, unsigned int pickups, double pickups_output);

  unsigned int getPickups() const;
  
  double getPickupsOutput() const;

  Electric& operator=(Electric const& other);
};

#endif

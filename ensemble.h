#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
class Ensemble{
private:
  
  
public:
  Ensemble();
  Ensemble(Ensemble const & p_ens);
  ~Ensemble();
  virtual bool isSTRin(string const & p_str) const = 0;
  virtual bool isEmpty() const = 0;
  virtual void addStr(string const & p_str) = 0;
  virtual void afficher() const = 0;
  virtual void removeSTR(string const & p_str) = 0;
  virtual void unionEns(Ensemble const & p_ens) = 0;
  virtual void intersectEns(Ensemble const & p_ens) = 0;
  virtual void diffEns(Ensemble const & p_ens) = 0;
  virtual string parcourirEns(unsigned int p_index) const = 0;
};






#endif
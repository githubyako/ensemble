#ifndef ENSEMBLETABLEAU_H
#define ENSEMBLETABLEAU_H
#include "ensemble.h"
class EnsembleTableau: public Ensemble{
private:
  string * m_strtab;
  unsigned int tabsize;
public:
  EnsembleTableau();
  EnsembleTableau(EnsembleTableau const & enstab);
  ~EnsembleTableau();
  bool isSTRin(string const & p_str) const;
  bool isEmpty() const;
  void addStr(string const & p_str);
  void afficher() const;
  void removeSTR(string const & p_str);
  void unionEns(Ensemble const & p_ens);
  void intersectEns(Ensemble const & p_ens);
  void diffEns(Ensemble const & p_ens);
  string parcourirEns(unsigned int p_index) const;
};


#endif
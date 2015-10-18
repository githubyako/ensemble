#include "ensembletableau.h"

EnsembleTableau::EnsembleTableau():m_strtab(new string[0]), tabsize(0)
{
  cout << "def ensembletab constructor calld\n";
}

EnsembleTableau::EnsembleTableau(EnsembleTableau const & enstab):m_strtab(new string[enstab.tabsize])
{
  for(int i=0;i<enstab.tabsize;++i){
    m_strtab[i] = enstab.m_strtab[i];
  }
  tabsize=enstab.tabsize;
  cout << "copy ensembletab constructor calld\n";
}

EnsembleTableau::~EnsembleTableau()
{
  delete [] m_strtab;
  //cout << "ensembletab destructor calld \n";
}

bool EnsembleTableau::isSTRin(const string& p_str) const
{
  bool result=false;
  for(int i=0;i<tabsize;++i){
    if (p_str.compare(m_strtab[i])==0)
      result = true;
  }
  return result;
}

bool EnsembleTableau::isEmpty() const
{
  bool result;
  (tabsize==0) ? result=true : result=false;
  return result;
}

void EnsembleTableau::addStr(const string& p_str)
{
  if(isSTRin(p_str)==false){
    string * temptab = new string[tabsize+1];
    for(int i=0;i<tabsize;++i){
      temptab[i]=m_strtab[i];
    }
    temptab[tabsize]=p_str;
    if(m_strtab != NULL){
      delete[] m_strtab;
    }
    m_strtab = temptab;
    tabsize++;
    
  }
}

void EnsembleTableau::afficher() const
{
  for(int i=0;i<tabsize;++i){
    
    cout << m_strtab[i] << "\n";
  }
  cout << "tabsize=" << tabsize << "\n\n";
}

void EnsembleTableau::removeSTR(const string& p_str)
{
  if(isSTRin(p_str)){
    int i;
    for(i=0;i<tabsize;++i){
      if (p_str.compare(m_strtab[i])==0)
	break;
    }
    string * temptab = new string[tabsize-1];
    for(int j=0;j<i;++j){
      temptab[j] = m_strtab[j];
    }
    for(int j=i+1;j<tabsize;++j){
      temptab[j-1] = m_strtab[j];
    }
    if(m_strtab != NULL){
      delete[] m_strtab;
    }
    m_strtab = temptab;
    tabsize--;
  }
}

void EnsembleTableau::unionEns(const Ensemble& p_ens)
{
  EnsembleTableau const & tempens = dynamic_cast<const EnsembleTableau&>(p_ens);
  for(int j=0;j<tempens.tabsize;++j){
    addStr(tempens.m_strtab[j]);
  }
}

void EnsembleTableau::intersectEns(const Ensemble& p_ens)
{
  EnsembleTableau const & tempens = dynamic_cast<const EnsembleTableau&>(p_ens);
  int j=0;
  for(int i=0;i<tabsize;++i){
    if(tempens.isSTRin(m_strtab[i-j])==false){
      removeSTR(m_strtab[i-j]);
      j++;
    }
  }
  
}

void EnsembleTableau::diffEns(const Ensemble& p_ens)
{
  EnsembleTableau const & tempens = dynamic_cast<const EnsembleTableau&>(p_ens);
  int j=0;
  for(int i=0;i<tabsize;++i){
    if(tempens.isSTRin(m_strtab[i-j])==true){
      removeSTR(m_strtab[i-j]);
      ++j;
    }
  }  
}

string EnsembleTableau::parcourirEns(unsigned int p_index) const
{
  string result;
  if(tabsize+1 >= p_index)
    result=m_strtab[p_index];
  return result;
}


#include "ensembletableau.h"
int main(int argc, char **argv) {
    std::cout << "Hello, noob!" << std::endl;
    
    EnsembleTableau enst1;
    EnsembleTableau enst2(enst1);
    enst2.addStr("lol mdr");
    enst2.afficher();
    enst2.addStr("lol mdr");
    enst2.afficher();
    enst2.addStr("bob l'éponge mange une soupe");
    enst2.afficher();
    enst2.addStr("nabab");
    enst2.afficher();
    enst2.removeSTR("bob l'éponge mange une soupe");
    enst2.afficher();
    EnsembleTableau enst3;
    enst3.addStr("bachibouzouk");
    enst3.addStr("vive la France");
    enst3.addStr("lol mdr");
    EnsembleTableau enst5(enst3);
    cout << "test d'union de enst3 et enst2 dans enst3\n";
    
    cout << "enst3:\n";
    enst3.afficher();
    
    cout << "enst2:\n";
    enst2.afficher();
    
    enst3.unionEns(enst2);
    
    cout << "nouvel enst3:\n";
    enst3.afficher();
    
    enst2.addStr("popcorn");
    enst2.addStr("mistral");
    enst3.addStr("popcorn");
    cout << "enst2:\n";
    enst2.afficher();
    cout << "enst3:\n";
    enst3.afficher();
    enst3.intersectEns(enst2);
    cout << "intersected enst2 and enst3 in enst3. Nouvel enst3:\n";
    enst3.afficher();
    
    EnsembleTableau enst4(enst3);
    cout << "enst4 = enst3\n";
    
    cout << "enst2:\n";
    enst2.afficher();
    cout << "enst5:\n";
    enst5.afficher();
    
    
    enst5.diffEns(enst2);
    
    cout << "diff'd enst5 & enst2 in enst5: \n";
    enst5.afficher();
    
    cout << enst5.parcourirEns(1) << "\n";
    
   
    
    
    return 0;
}

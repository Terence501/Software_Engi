#ifndef BUILDING_H
#define BUILDING_H

#include "dyn_array.h"
#include <iostream>

class Rock; // Forward declaration : Rock is defined elsewhere

class Building {
public:
    // Constructeur avec paramètres
    Building(int id, int nb_rocks);

    // Constructeur par défaut
    Building() : id_(-1), rocks_() {}

    // Constructeur de copie
    Building(const Building& rhs);

    // Opérateur d’affectation
    Building& operator=(const Building& rhs);

    // Destructeur
    ~Building();

    // Accesseurs
    const Rock* get_rock(int index) const;

    // Fonction pour échanger des roches entre bâtiments
    bool swap_rock(Building& partner, unsigned int this_index, unsigned int partner_index);

    // Affichage
    friend std::ostream& operator<<(std::ostream& out, const Building& rhs);

private:
    int id_;
    DynArray<Rock*> rocks_;
};

#endif // BUILDING_H

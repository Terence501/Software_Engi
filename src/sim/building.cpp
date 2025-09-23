
#include <iostream>
#include <sim/building.h>
#include <sim/rock.h>

// Constructeur avec paramètres
Building::Building( int id, int nb_rocks ) : id_( id ), rocks_()
{
    std::cout << "Building::Building(" << id << ") at " << this << std::endl;

    for( int i = 0; i < nb_rocks; ++i )
    {
        rocks_.push_back( new Rock() ); // suppose que DynArray a push_back
    }
}

// Constructeur de copie
Building::Building( const Building& rhs ) : id_( rhs.id_ ), rocks_()
{
    for( unsigned int i = 0; i < rhs.rocks_.size(); ++i )
    {
        rocks_.push_back( new Rock( *rhs.rocks_[i] ) );
    }
}

// Destructeur
Building::~Building()
{
    for( unsigned int i = 0; i < rocks_.size(); ++i )
    {
        delete rocks_[i];
    }
}

// Opérateur d’affectation
Building& Building::operator=( const Building& rhs )
{
    std::cout << "Building::operator= called on " << this << " from " << &rhs
              << std::endl;

    if( this != &rhs )
    {
        // Nettoyer les anciens rocks
        for( unsigned int i = 0; i < rocks_.size(); ++i )
        {
            delete rocks_[i];
        }

        id_ = rhs.id_;
        for( unsigned int i = 0; i < rhs.rocks_.size(); ++i )
        {
            rocks_.push_back( new Rock( *rhs.rocks_[i] ) );
        }
    }
    return *this;
}

// Accesseur
const Rock* Building::get_rock( int index ) const
{
    if( index >= 0 && static_cast< unsigned int >( index ) < rocks_.size() )
    {
        return rocks_[index];
    }
    return nullptr;
}

// Affichage
std::ostream& operator<<( std::ostream& out, const Building& rhs )
{
    out << "Building #" << rhs.id_ << " with " << rhs.rocks_.size()
        << " rocks.";
    return out;
}

// swap_rock
bool Building::swap_rock(
    Building& partner, unsigned int this_index, unsigned int partner_index )
{
    if( this_index < rocks_.size() && partner_index < partner.rocks_.size() )
    {
        Rock* tmp = rocks_[this_index];
        rocks_[this_index] = partner.rocks_[partner_index];
        partner.rocks_[partner_index] = tmp;
        return true;
    }
    return false;
}

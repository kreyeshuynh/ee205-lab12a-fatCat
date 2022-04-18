// Copyright (c) 2022. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Weight.h"

using namespace std;

const float Weight::UNKNOWN_WEIGHT = -1;
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;

const string Weight::POUND_LABEL = "Pound" ; ///< @see https://en.wikipedia.org/wiki/Pound_(mass)
const string Weight::KILO_LABEL  = "Kilo" ;  ///< @see https://en.wikipedia.org/wiki/Kilogram
const string Weight::SLUG_LABEL  = "Slug" ;  ///< @see https://en.wikipedia.org/wiki/Slug_(unit)


Weight::Weight() noexcept {
assert( validate() );
}

Weight::Weight( const float newWeight ) {
    setWeight( newWeight );
    assert( validate() );
}

Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight ) noexcept {
unitOfWeight = newUnitOfWeight ;
assert( validate() );
}

Weight::Weight( const float newWeight, const Weight::UnitOfWeight newUnitOfWeight ) : Weight( newUnitOfWeight ) {
    setWeight( newWeight, newUnitOfWeight );
    assert( validate() );
}


Weight::Weight( const float newWeight, const float newMaxWeight ) {
    setMaxWeight( newMaxWeight );
    setWeight( newWeight );
    assert( validate() );
}


Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight, const float newMaxWeight ) : Weight( newUnitOfWeight ) {
    setMaxWeight( newMaxWeight );
    assert( validate() );
}

Weight::Weight( const float newWeight
        ,const Weight::UnitOfWeight newUnitOfWeight
        ,const float newMaxWeight ) : Weight( newUnitOfWeight, newMaxWeight ) {
    setWeight( newWeight );
    assert( validate() );
}


bool Weight::isWeightKnown() const noexcept {
    assert( validate() );

    return bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    assert( validate() );

    return bHasMax;
}

float Weight::getWeight() const noexcept {
    assert( validate() );

    if( bIsKnown )
        return weight ;
    else
        return UNKNOWN_WEIGHT ;
}

float Weight::getWeight( const Weight::UnitOfWeight weightUnits ) const noexcept {
    assert( validate() );

    return convertWeight( weight, unitOfWeight, weightUnits );
}

float Weight::getMaxWeight() const noexcept {
    assert( validate() );

    if( bHasMax )
        return maxWeight ;
    else
        return UNKNOWN_WEIGHT ;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    assert( validate() );

    return unitOfWeight ;
}

void Weight::setWeight( const float newWeight ) {
    assert( validate() );

    if( !isWeightValid( newWeight ) ) {
        return false;
    }

    weight = newWeight ;
    bIsKnown = true ;
    assert( validate() );
}

void Weight::setWeight( const float newWeight, const Weight::UnitOfWeight weightUnits ) {
    setWeight( convertWeight( newWeight, weightUnits, unitOfWeight ));
}

void Weight::setMaxWeight( const float newMaxWeight ) {

    assert( !bHasMax );

    if( !isWeightValid( newMaxWeight) ) {
       return false;
    }
    maxWeight = newMaxWeight;
    bHasMax = true ;

}

bool Weight::isWeightValid( const float checkWeight ) const noexcept {

    if( checkWeight <= 0 ) {
        cout << "Weight [" << checkWeight << "] can not be <= 0" << endl ;
        return false;
}

    if( bHasMax ) {
        if( checkWeight > maxWeight ) {
            cout << "Weight [" << checkWeight << "] is > the maximum weight [" << maxWeight << "]" << endl ;
            return false;
        }
    }

    return true;
}

bool Weight::validate() const noexcept {
    if( bHasMax ) {
        if( !isWeightValid(( maxWeight))) {
          cout << "Max weight is <= 0" << endl;
          return false;
}

    assert( maxWeight > 0 );
}

    if( bIsKnown ) {
        if( !isWeightValid( weight ) ) {
        return false;
}
    assert( weight > 0);

    if( bHasMax ) {
        assert( weight <= maxWeight );
    }
}

    return true;
}

float Weight::fromKilogramToPound( const float kilogram ) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}

float Weight::fromPoundToKilogram( const float pound ) noexcept {
    return pound * KILOS_IN_A_POUND ;
}

float Weight::fromSlugToPound( const float slug ) noexcept {
    return slug / SLUGS_IN_A_POUND ;
}

float Weight::fromPoundToSlug( const float pound ) noexcept {
    return pound * SLUGS_IN_A_POUND ;
}

float Weight::convertWeight( const float fromWeight ,const UnitOfWeight fromUnit ,const UnitOfWeight toUnit ) noexcept {

    float commonWeight = UNKNOWN_WEIGHT;

    switch( fromUnit ) {
        case POUND: commonWeight = fromWeight ;
                    break;
        case KILO: commonWeight = fromKilogramToPound( fromWeight ) ;
                    break;
        case SLUG: commonWeight = fromSlugToPound( fromWeight ) ;
                    break;
        default: return false;
    }

float toWeight = UNKNOWN_WEIGHT;

    switch( toUnit ) {
        case POUND: toWeight = commonWeight ;
                    break;
        case KILO: toWeight = fromPoundToKilogram( commonWeight );
                    break;
        case SLUG: toWeight = fromPoundToSlug( commonWeight );
                    break;
default: return false;
}

return toWeight ;
}


/// Format a line for dumping the members of a class to the console
#define FORMAT_LINE( className, member ) std::cout \
                                      << std::setw(8) << (className) \
                                      << std::setw(20) << (member)   \
                                      << std::setw(52)  /* (data) */


void Weight::dump() const noexcept {

cout << setw(80) << setfill( '=' ) << "" << endl ;
cout << setfill( ' ' ) ;   // Space pad
cout << left ;             // Left justify
cout << boolalpha ;        // Print `true` and `false` for `bool`s

FORMAT_LINE( "Weight", "this" )         << this         << endl ;
FORMAT_LINE( "Weight", "isKnown" )      << bIsKnown     << endl ;
FORMAT_LINE( "Weight", "weight" )       << weight       << endl ;
FORMAT_LINE( "Weight", "unitOfWeight" ) << unitOfWeight << endl ;
FORMAT_LINE( "Weight", "hasMax" )       << bHasMax      << endl ;
FORMAT_LINE( "Weight", "maxWeight" )    << maxWeight    << endl ;
// FORMAT_LINE( "Weight", "<<" ) << this << endl ;
}

std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_Weight ) {
    if( !rhs_Weight.isWeightKnown() && !rhs_Weight.hasMaxWeight() ) {
        lhs_stream << "Unknown" ;
        return lhs_stream;
    }
    else if( rhs_Weight.isWeightKnown() ) {
        lhs_stream << rhs_Weight.getWeight();
    } else {
        lhs_stream << "Unknown";
    }

    if( rhs_Weight.hasMaxWeight() ) {
        lhs_stream << " out of " << rhs_Weight.getMaxWeight();
    }

    lhs_stream << " " << rhs_Weight.getWeightUnit() ;


    if(    ( !rhs_Weight.hasMaxWeight() && rhs_Weight.getWeight() > 1 )
           || ( rhs_Weight.hasMaxWeight() && rhs_Weight.getMaxWeight() > 1 ) ) {
        lhs_stream << "s";
    }

    return lhs_stream;
}


std::ostream& operator<<( ostream& lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO:  return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG:  return lhs_stream << Weight::SLUG_LABEL ;
        default: throw out_of_range( "The unit can not be converted to a string" );
    }
}


bool Weight::operator==( const Weight& rhs_Weight ) const {

    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight == rhs_weight;
}


bool Weight::operator<( const Weight& rhs_Weight ) const {

    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight < rhs_weight;
}



Weight& Weight::operator+=( const float rhs_addToWeight ) {
    if( !bIsKnown ) {
        return false;
    }

    setWeight( weight + rhs_addToWeight );

    return *this;
}
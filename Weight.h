// Copyright (c) 2022. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <ostream>

#pragma once
class Weight {
public:  ////////////// Enumerations //////////////
    /// A unit of measure for weight
    enum UnitOfWeight { POUND, KILO, SLUG };

public:
    static const float UNKNOWN_WEIGHT;

    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;

    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

private:
    bool bIsKnown = false;
    bool bHasMax = false;
    enum UnitOfWeight unitOfWeight = POUND;

    float weight{} ;
    float maxWeight{};

public:
    explicit Weight() noexcept;
    explicit Weight( float newWeight );
    explicit Weight( UnitOfWeight newUnitOfWeight ) noexcept;
    explicit Weight( float newWeight, UnitOfWeight newUnitOfWeight );
    explicit Weight( float newWeight, float newMaxWeight );
    explicit Weight( UnitOfWeight newUnitOfWeight, float newMaxWeight );
    explicit Weight( float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight );

public:
    bool  isWeightKnown() const noexcept;
    bool  hasMaxWeight() const noexcept;
    float getWeight() const noexcept;
    float getWeight( UnitOfWeight weightUnits ) const noexcept;
    float getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit() const noexcept;

public:
    void setWeight( float newWeight );
    void setWeight( float newWeight, UnitOfWeight weightUnits );

private:
    void setMaxWeight( float newMaxWeight );

public:
    static float fromKilogramToPound( float kilogram ) noexcept;
    static float fromPoundToKilogram( float pound ) noexcept;
    static float fromSlugToPound( float slug ) noexcept;
    static float fromPoundToSlug( float pound ) noexcept;


    static float convertWeight( float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit ) noexcept;

public:
    bool isWeightValid( float checkWeight ) const noexcept;
    bool validate() const noexcept;
    void dump() const noexcept;

public:
    bool operator==( const Weight& rhs_Weight ) const;
    bool operator<( const Weight& rhs_Weight ) const;
    Weight& operator+=( float rhs_addToWeight );
};

std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_Weight ) ;
std::ostream& operator<<( std::ostream& lhs_stream, Weight::UnitOfWeight rhs_UnitOfWeight );


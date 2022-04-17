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

class Weight {
public:  ////////////// Enumerations //////////////
    /// A unit of measure for weight
    enum UnitOfWeight { POUND, KILO, SLUG };

    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;

    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;
};


///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
https://www.etlcpp.com

Copyright(c) 2014 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

/*[[[cog
import cog
cog.outl("#if 0")
]]]*/
/*[[[end]]]*/
#error THIS HEADER IS A GENERATOR. DO NOT INCLUDE.
/*[[[cog
import cog
cog.outl("#endif")
]]]*/
/*[[[end]]]*/

/*[[[cog
import cog
cog.outl("//***************************************************************************")
cog.outl("// This file has been auto generated. Do not edit this file.")
cog.outl("//***************************************************************************")
]]]*/
/*[[[end]]]*/

//***************************************************************************
// To generate to header file, run this at the command line.
// Note: You will need Python and COG installed.
//
// python -m cogapp -d -e -osmallest.h -DNTypes=<n> smallest_generator.h
// Where <n> is the number of types to support.
//
// e.g.
// To generate handlers for up to 16 types...
// python -m cogapp -d -e -osmallest.h -DNTypes=16 smallest_generator.h
//
// See generate.bat
//***************************************************************************

#ifndef ETL_SMALLEST_INCLUDED
#define ETL_SMALLEST_INCLUDED

#include <stdint.h>

#include "platform.h"
#include "integral_limits.h"

///\defgroup smallest smallest
///\ingroup utilities

namespace etl
{
  /*[[[cog
  import cog
  cog.outl("//***************************************************************************")
  cog.outl("/// Template to determine the smallest type and size.")
  cog.outl("/// Supports up to %s types." % NTypes)
  cog.outl("/// Defines 'value_type' which is the type of the smallest parameter.")
  cog.outl("/// Defines 'size' which is the size of the smallest parameter.")
  cog.outl("///\ingroup smallest")
  cog.outl("//***************************************************************************")
  cog.out("template <typename T1, ")
  for n in range(2, int(NTypes)):
      cog.out("typename T%s = void, " % n)
      if n % 4 == 0:
          cog.outl("")
          cog.out("          ")
  cog.outl("typename T%s = void>" % int(NTypes))
  cog.outl("struct smallest_type")
  cog.outl("{")
  cog.outl("private:")
  cog.outl("")
  cog.outl("  // Declaration.")
  cog.outl("  template <const bool Boolean, typename TrueType, typename FalseType>")
  cog.outl("  struct choose_type;")
  cog.outl("")
  cog.outl("  // Specialisation for 'true'.")
  cog.outl("  // Defines 'type' as 'TrueType'.")
  cog.outl("  template <typename TrueType, typename FalseType>")
  cog.outl("  struct choose_type<true, TrueType, FalseType>")
  cog.outl("  {")
  cog.outl("    typedef TrueType type;")
  cog.outl("  };")
  cog.outl("")
  cog.outl("  // Specialisation for 'false'. ")
  cog.outl("  // Defines 'type' as 'FalseType'.")
  cog.outl("  template <typename TrueType, typename FalseType>")
  cog.outl("  struct choose_type<false, TrueType, FalseType>")
  cog.outl("  {")
  cog.outl("    typedef FalseType type;")
  cog.outl("  };")
  cog.outl("")
  cog.outl("public:")
  cog.outl("")
  cog.outl("  // Define 'smallest_other' as 'smallest_type' with all but the first parameter. ")
  cog.out("  typedef typename smallest_type<")
  for n in range(2, int(NTypes)):
      cog.out("T%s, " % n)
      if n % 16 == 0:
          cog.outl("")
          cog.out("                                ")
  cog.outl("T%s>::type smallest_other;" % int(NTypes))
  cog.outl("")
  cog.outl("  // Set 'type' to be the smallest of the first parameter and any of the others.")
  cog.outl("  // This is recursive.")
  cog.outl("  typedef typename choose_type<(sizeof(T1) < sizeof(smallest_other)), // Boolean")
  cog.outl("                                T1,                                   // TrueType")
  cog.outl("                                smallest_other>                       // FalseType")
  cog.outl("                                ::type type;                          // The smallest type of the two.")
  cog.outl("")
  cog.outl("  // The size of the smallest type.")
  cog.outl("  enum")
  cog.outl("  {")
  cog.outl("    size = sizeof(type)")
  cog.outl("  };")
  cog.outl("};")
  cog.outl("")
  cog.outl("//***************************************************************************")
  cog.outl("// Specialisation for one template parameter.")
  cog.outl("//***************************************************************************")
  cog.outl("template <typename T1>")
  cog.out("struct smallest_type<T1,   ")
  for n in range(2, int(NTypes)):
      cog.out("void, ")
      if n % 8 == 0:
          cog.outl("")
          cog.out("                     ")
  cog.outl("void>")
  cog.outl("{")
  cog.outl("  typedef T1 type;")
  cog.outl("")
  cog.outl("  enum")
  cog.outl("  {")
  cog.outl("    size = sizeof(type)")
  cog.outl("  };")
  cog.outl("};")
  ]]]*/
  /*[[[end]]]*/
  
  namespace private_smallest
  {
    //*************************************************************************
    // Determine the type to hold the number of bits based on the index.
    //*************************************************************************
    template <const int index>
    struct best_fit_uint_type;
    
    //*************************************************************************
    // Less than or equal to 8 bits.
    //*************************************************************************
    template <>
    struct best_fit_uint_type<0>
    {
      typedef uint_least8_t type;
    };

    //*************************************************************************
    // 9 to 16 bits.
    //*************************************************************************
    template <>
    struct best_fit_uint_type<1>
    {
      typedef uint_least16_t type;
    };

    //*************************************************************************
    // 17 to 31 bits.
    //*************************************************************************
    template <>
    struct best_fit_uint_type<2>
    {
      typedef uint_least32_t type;
    };

    //*************************************************************************
    // Greater than 32 bits.
    //*************************************************************************
    template <>
    struct best_fit_uint_type<3>
    {
      typedef uint_least64_t type;
    };

    //*************************************************************************
    // Determine the type to hold the number of bits based on the index.
    //*************************************************************************
    template <const int index>
    struct best_fit_int_type;

    //*************************************************************************
    // Less than or equal to 8 bits.
    //*************************************************************************
    template <>
    struct best_fit_int_type<0>
    {
      typedef int_least8_t type;
    };

    //*************************************************************************
    // 9 to 16 bits.
    //*************************************************************************
    template <>
    struct best_fit_int_type<1>
    {
      typedef int_least16_t type;
    };

    //*************************************************************************
    // 17 to 31 bits.
    //*************************************************************************
    template <>
    struct best_fit_int_type<2>
    {
      typedef int_least32_t type;
    };

    //*************************************************************************
    // Greater than 32 bits.
    //*************************************************************************
    template <>
    struct best_fit_int_type<3>
    {
      typedef int_least64_t type;
    };
  }

  //***************************************************************************
  /// Template to determine the smallest unsigned int type that can contain a 
  /// value with the specified number of bits.
  /// Defines 'type' which is the type of the smallest unsigned integer.
  ///\ingroup smallest
  //***************************************************************************
  template <const size_t NBITS>
  struct smallest_uint_for_bits
  {
  private:
    
    // Determines the index of the best unsigned type for the required number of bits.
    static const int TYPE_INDEX = ((NBITS >  8) ? 1 : 0) + 
                                  ((NBITS > 16) ? 1 : 0) +
                                  ((NBITS > 32) ? 1 : 0);

  public:

    typedef typename private_smallest::best_fit_uint_type<TYPE_INDEX>::type type;
  };

  //***************************************************************************
  /// Template to determine the smallest signed int type that can contain a 
  /// value with the specified number of bits.
  /// Defines 'type' which is the type of the smallest signed integer.
  ///\ingroup smallest
  //***************************************************************************
  template <const size_t NBITS>
  struct smallest_int_for_bits
  {
  private:

    // Determines the index of the best unsigned type for the required number of bits.
    static const int TYPE_INDEX = ((NBITS >  8) ? 1 : 0) +
                                  ((NBITS > 16) ? 1 : 0) +
                                  ((NBITS > 32) ? 1 : 0);

  public:

    typedef typename private_smallest::best_fit_int_type<TYPE_INDEX>::type type;
  };

  //***************************************************************************
  /// Template to determine the smallest unsigned int type that can contain the
  /// specified unsigned value.
  /// Defines 'type' which is the type of the smallest unsigned integer.
  ///\ingroup smallest
  //***************************************************************************
  template <const uintmax_t VALUE>
  struct smallest_uint_for_value
  {
  private:

    // Determines the index of the best unsigned type for the required value.
    static const int TYPE_INDEX = ((VALUE > UINT_LEAST8_MAX)  ? 1 : 0) +
                                  ((VALUE > UINT16_MAX) ? 1 : 0) + 
                                  ((VALUE > UINT32_MAX) ? 1 : 0);

  public:

    typedef typename private_smallest::best_fit_uint_type<TYPE_INDEX>::type type;
  };

  //***************************************************************************
  /// Template to determine the smallest int type that can contain the
  /// specified signed value.
  /// Defines 'type' which is the type of the smallest signed integer.
  ///\ingroup smallest
  //***************************************************************************
  template <const intmax_t VALUE>
  struct smallest_int_for_value
  {
  private:

    // Determines the index of the best signed type for the required value.
    static const int TYPE_INDEX = (((VALUE > INT_LEAST8_MAX)  || (VALUE < INT_LEAST8_MIN))  ? 1 : 0) + 
                                  (((VALUE > INT16_MAX) || (VALUE < INT16_MIN)) ? 1 : 0) +
                                  (((VALUE > INT32_MAX) || (VALUE < INT32_MIN)) ? 1 : 0);

  public:

    typedef typename private_smallest::best_fit_int_type<TYPE_INDEX>::type type;
  };
}

#endif

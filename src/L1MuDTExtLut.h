//-------------------------------------------------
//
/**  \class L1MuDTExtLut
 *
 *   Look-up tables for extrapolation
 *
 *
 *   $Date: 2006/06/01 00:00:00 $
 *   $Revision: 1.1 $
 *
 *   N. Neumeister            CERN EP
 */
//
//--------------------------------------------------
#ifndef L1MUDT_EXT_LUT_H
#define L1MUDT_EXT_LUT_H

//---------------
// C++ Headers --
//---------------

#include <vector>
#include <map>

//----------------------
// Base Class Headers --
//----------------------


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//              ---------------------
//              -- Class Interface --
//              ---------------------


class L1MuDTExtLut {

  public:

    /// constructor
    L1MuDTExtLut();

    /// destructor
    virtual ~L1MuDTExtLut();

    /// reset extrapolation look-up tables
    void reset();
    
    /// load extrapolation look-up tables
    int load();

    /// print extrapolation look-up tables
    void print() const;

    /// get low_value for a given address
    int getLow(int ext_ind, int address) const;
    
    /// get high_value for a given address
    int getHigh(int ext_ind, int address) const;

  private:

    /// set precision for look-up tables
    void setPrecision();
    
  private:

    /// helper class for look-up tables
    class LUT {
      public:
        typedef map<int, int, less<int> > LUTmap;

        LUTmap low;
        LUTmap high;
    };

    vector<LUT*> ext_lut;

    unsigned short int nbit_phi;
    unsigned short int nbit_phib;
    
};

#endif

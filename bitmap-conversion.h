#ifndef BITMAP_CONVERSION_H
#define BITMAP_CONVERSION_H

#include <array>

template<typename T0,typename T1,size_t N>
class BitMapConversion {

    std::array<std::pair<T0,T1>,N> Map;
  public :
    BitMapConversion(const std::array<std::pair<T0,T1>,N>& map)
        : Map(map)
    {
    }

    T1 t02T1(T0 t0) const
    {
        T1 res=static_cast<T1>(0);
        for(const auto& [t0i,t1i] : Map)
        {
            if(bool(t0 & t0i))
            {
                res=res | t1i;
            }
        }
        return res;
    }
    
    T0 t12T0(T1 t1) const
    {
        T1 res=static_cast<T0>(0);
        for(const auto& [t0i,t1i] : Map)
        {
            if(bool(t1 & t1i))
            {
                res=res | t0i;
            }
        }
        return res;
    }
};




#endif // BITMAP-CONVERSION_H


//  self

    #include "ios-base-impl.h"


//  c++

    #include <ios>

// we can not impl in header and need to include ios because with fwd decl
// we do not know that std::ios_base is base of std::basic_ios

namespace stream
{
    BasicIOSImpl :: BasicIOSImpl(std::basic_ios<char>& base)
      : IOSBaseImpl{base}
      , BasicIOS(base)
    {
    }
}

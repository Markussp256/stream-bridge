
//  self

    #include "ios-base-impl.h"


//  c++

    #include <ios>



namespace stream
{
    BasicIOSImpl :: BasicIOSImpl(std::basic_ios<char>& base)
      : IOSBaseImpl{base}
      , BasicIOS(base)
    {
    }
}

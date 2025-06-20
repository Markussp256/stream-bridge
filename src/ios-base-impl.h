#ifndef IOS_BASE_IMPL_H
#define IOS_BASE_IMPL_H

#include <iosfwd>

namespace stream
{
    class IOSBaseImpl
    {
        std::ios_base& IOSBase;
      public :
        explicit IOSBaseImpl(std::ios_base& iosBase)
            : IOSBase(iosBase)
        {
        }
        std::ios_base& iosBase(void) { return IOSBase; }
    };

    class BasicIOSImpl : public IOSBaseImpl
    {
        std::basic_ios<char>& BasicIOS;
      public :
          explicit BasicIOSImpl(std::basic_ios<char>& base);

         std::basic_ios<char>& basicIOS(void) { return BasicIOS; }
    };
}

#endif // IOS-BASE-IMPL_H

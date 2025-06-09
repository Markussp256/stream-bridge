#ifndef IOS_BASE_IMPL_H
#define IOS_BASE_IMPL_H

#include <iosfwd>

namespace stream
{
    class BaseImpl
    {
      public :
        std::basic_ios<char>& Base;
    };
}

#endif // IOS-BASE-IMPL_H

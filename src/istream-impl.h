#ifndef ISTREAM_IMPL_H
#define ISTREAM_IMPL_H

//  app

    #include "ios-base-impl.h"


//  c++

    #include <istream>


namespace stream
{
    class IStreamImpl : public BasicIOSImpl
    {
        public :
        std::istream& Is;
        IStreamImpl(std::istream& is)
            : BasicIOSImpl{is}
            , Is(is)
        {
        }
    };
}

#endif // ISTREAM-IMPL_H

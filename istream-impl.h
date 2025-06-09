#ifndef ISTREAM_IMPL_H
#define ISTREAM_IMPL_H

//  app

    #include "ios-base-impl.h"


//  c++

    #include <istream>


namespace stream
{
    class IStreamImpl : public BaseImpl
    {
        public :
        std::istream& Is;
        IStreamImpl(std::istream& is)
            : BaseImpl{is}
            , Is(is)
        {
        }
    };
}

#endif // ISTREAM-IMPL_H

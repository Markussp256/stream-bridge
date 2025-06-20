#ifndef OSTREAM_IMPL_H
#define OSTREAM_IMPL_H

//  app

    #include "ios-base-impl.h"


//  c++

    #include <ostream>


namespace stream
{
    class OStreamImpl : public BasicIOSImpl
    {
        public :
        std::ostream& Os;
        OStreamImpl(std::ostream& os)
            : BasicIOSImpl{os}
            , Os(os)
        {
        }
    };
}

#endif // OSTREAM-IMPL_H

//  self

    #include "iostream-bridge.h"


//  app

    #include "istream-impl.h"
    #include "ostream-impl.h"


//  c++

    #include <iostream>


namespace stream
{
    static IStreamImpl& getCInImpl() {
        static IStreamImpl impl{std::cin};
        return impl;
    }

    static OStreamImpl& getCOutImpl() {
        static OStreamImpl impl{std::cout};
        return impl;
    }

    static OStreamImpl& getCErrImpl() {
        static OStreamImpl impl{std::cerr};
        return impl;
    }

    istream cin{getCInImpl()};
    ostream cout{getCOutImpl()};
    ostream cerr{getCErrImpl()};
}


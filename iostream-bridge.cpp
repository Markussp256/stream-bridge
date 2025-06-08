//  self

    #include "iostream-bridge.h"


//  app

    #include "ostream-impl.h"


//  c++

    #include <iostream>


namespace stream
{
    static OStreamImpl COutImpl{std::cout};
    static OStreamImpl CErrImpl{std::cerr};
    ostream            cout(&COutImpl);
    ostream            cerr(&CErrImpl);
}


//  self

    #include "iostream-bridge.h"


//  app

    #include "ostream-impl.h"


//  c++

    #include <iostream>


namespace stream
{
    static OStreamImpl CoutImpl{std::cout};
    static OStreamImpl CErrImpl{std::cerr};
    stream::ostream cout(&CoutImpl);
    stream::ostream cerr(&CErrImpl);
}


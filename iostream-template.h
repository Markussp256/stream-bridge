#ifndef IOSTREAM_TEMPLATE_H
#define IOSTREAM_TEMPLATE_H

#include "istream-impl.h"
#include "ostream-impl.h"


namespace stream
{
    template<class stdistream_t>
    class IStreamImplTemplate : public stdistream_t
    {
      public :
        using stdistream_t::stdistream_t;
        IStreamImpl Is{*this};
    };

    template<class stdostream_t>
    class OStreamImplTemplate : public stdostream_t
    {
      public :
        using stdostream_t::stdostream_t;
        OStreamImpl Os{*this};
    };

    template<class stdstream_t>
    class StreamImplTemplate : public stdstream_t
    {
      public :
        using stdstream_t::stdstream_t;
        IStreamImpl Is{*this};
        OStreamImpl Os{*this};
    };
}


#endif // IOSTREAM-TEMPLATE_H

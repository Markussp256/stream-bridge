#ifndef OSTREAM_IMPL_H
#define OSTREAM_IMPL_H

#include <ostream>

namespace stream
{
    class OStreamImpl { public : std::ostream& Os; };

    template<class stdostream_t>
    class OStreamImplTemplate : public stdostream_t
    {
        OStreamImpl OS{*this};
      public :
        using stdostream_t::stdostream_t;
        OStreamImpl& os (void) { return OS; }
    };
}

#endif // OSTREAM-IMPL_H

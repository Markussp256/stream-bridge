//  self

    #include "sstream-bridge.h"


//  app

    #include "ostream-impl.h"


//  c++

    #include <sstream>



namespace stream
{

    class OSStreamImpl : public OStreamImplTemplate<std::ostringstream>
    {
      public :
        using OStreamImplTemplate<std::ostringstream>::OStreamImplTemplate;
    };

    ostringstream ::  ostringstream(OSStreamImpl* impl)
        : ostream(&impl->os())
        , Impl(impl)
    {
    }

    ostringstream ::  ostringstream(void) : ostringstream(new OSStreamImpl()) {}
    ostringstream ::  ostringstream(const std::string& str) : ostringstream(new OSStreamImpl(str)) {}
    ostringstream :: ~ostringstream(void) { delete Impl; }
    std::string ostringstream :: str(void) const { return Impl -> str(); }
}

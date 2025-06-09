//  self

    #include "sstream-bridge.h"


//  app

    #include "iostream-template.h"


//  c++

    #include <sstream>


namespace stream
{

    class IStringStreamImpl : public IStreamImplTemplate<std::istringstream>
    {
      public :
        using IStreamImplTemplate<std::istringstream>::IStreamImplTemplate;
    };

    istringstream ::  istringstream(IStringStreamImpl* impl)
        : base(&impl->Is)
        , istream(&impl->Is)
        , Impl(impl)
    {
    }

    istringstream ::  istringstream(void) : istringstream(new IStringStreamImpl()) {}
    istringstream ::  istringstream(std::string&& str) : istringstream(new IStringStreamImpl(std::move(str))) {}
    istringstream :: ~istringstream(void) { delete Impl; }
    std::string istringstream :: str(void) const { return Impl -> str(); }


    class OStringStreamImpl : public OStreamImplTemplate<std::ostringstream>
    {
      public :
        using OStreamImplTemplate<std::ostringstream>::OStreamImplTemplate;
    };

    ostringstream ::  ostringstream(OStringStreamImpl* impl)
        : base(&impl->Os)
        , ostream(&impl->Os)
        , Impl(impl)
    {
    }

    ostringstream ::  ostringstream(void) : ostringstream(new OStringStreamImpl()) {}
    ostringstream ::  ostringstream(std::string&& str) : ostringstream(new OStringStreamImpl(std::move(str))) {}
    ostringstream :: ~ostringstream(void) { delete Impl; }
    std::string ostringstream :: str(void) const { return Impl -> str(); }
    
    struct StringStreamImpl : public StreamImplTemplate<std::stringstream>
    {
      public :
        using StreamImplTemplate<std::stringstream>::StreamImplTemplate;
    };

    stringstream ::  stringstream(StringStreamImpl* impl)
        : base(&impl->Is)
        , istream(&impl->Is)
        , ostream(&impl->Os)
        , Impl(impl)
    {
    }

    stringstream ::  stringstream(void) : stringstream(new StringStreamImpl()) {}
    stringstream ::  stringstream(std::string&& str) : stringstream(new StringStreamImpl(std::move(str))) {}
    stringstream :: ~stringstream(void) { delete Impl; }
    std::string stringstream :: str(void) const { return Impl -> str(); }

}

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
        : basic_ios(&impl->Is)
        , istream(&impl->Is)
        , Impl(impl)
    {
    }

    istringstream ::  istringstream(void) : istringstream(new IStringStreamImpl()) {}
    istringstream :: ~istringstream(void) { delete Impl; }
    istringstream ::  istringstream(const std::string& str) : istringstream(new IStringStreamImpl(str)) {}
    std::string istringstream :: str(void) const { return Impl -> str(); }


    class OStringStreamImpl : public OStreamImplTemplate<std::ostringstream>
    {
      public :
        using OStreamImplTemplate<std::ostringstream>::OStreamImplTemplate;
    };

    ostringstream ::  ostringstream(OStringStreamImpl* impl)
        : basic_ios(&impl->Os)
        , ostream(&impl->Os)
        , Impl(impl)
    {
    }

    ostringstream ::  ostringstream(void) : ostringstream(new OStringStreamImpl()) {}
    ostringstream :: ~ostringstream(void) { delete Impl; }
    ostringstream ::  ostringstream(const std::string& str) : ostringstream(new OStringStreamImpl(str)) {}
    std::string ostringstream :: str(void) const { return Impl -> str(); }
    
    struct StringStreamImpl : public StreamImplTemplate<std::stringstream>
    {
      public :
        using StreamImplTemplate<std::stringstream>::StreamImplTemplate;
    };

    stringstream ::  stringstream(StringStreamImpl* impl)
        : basic_ios(&impl->Is)
        , istream(&impl->Is)
        , ostream(&impl->Os)
        , Impl(impl)
    {
    }

    stringstream ::  stringstream(void) : stringstream(new StringStreamImpl()) {}
    stringstream :: ~stringstream(void) { delete Impl; }
    stringstream ::  stringstream(const std::string& str) : stringstream(new StringStreamImpl(str)) {}
    std::string stringstream :: str(void) const { return Impl -> str(); }

}

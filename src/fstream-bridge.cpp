//  self

    #include "fstream-bridge.h"


//  app

    #include "ios-bridge.h"
    #include "iostream-template.h"


//  c++

    #include <fstream>
    #include <string>


namespace stream
{
    class IFStreamImpl : public IStreamImplTemplate<std::ifstream>
    {
        public :
            using IStreamImplTemplate<std::ifstream>::IStreamImplTemplate;
    };
    
    ifstream ::  ifstream(IFStreamImpl* impl)
        : basic_ios(&impl->Is)
        , istream(&impl->Is)
        , Impl(impl)
    {
    }

    ifstream ::  ifstream(void) : ifstream(new IFStreamImpl()) {}
    ifstream ::  ifstream(const std::string& fileName, ios_base::openmode om)
                                : ifstream(new IFStreamImpl(fileName, streamOpenMode2stdopenmode(om))) {}
    ifstream :: ~ifstream(void) { delete Impl; }
    void ifstream :: open   (const std::string& fileName, ios_base::openmode om) { Impl->open(fileName,streamOpenMode2stdopenmode(om)); }
    bool ifstream :: is_open(void) const { return Impl->is_open(); }
    void ifstream :: close  (void) const { Impl->close(); }
    
    class OFStreamImpl : public OStreamImplTemplate<std::ofstream>
    {
        public :
            using OStreamImplTemplate<std::ofstream>::OStreamImplTemplate;
    };
    
    ofstream ::  ofstream(OFStreamImpl* impl)
        : basic_ios(&impl->Os)
        , ostream(&impl->Os)
        , Impl(impl)
    {
    }

    ofstream ::  ofstream(void) : ofstream(new OFStreamImpl()) {}
    ofstream ::  ofstream(const std::string& fileName, ios_base::openmode om)
                                : ofstream(new OFStreamImpl(fileName,streamOpenMode2stdopenmode(om))) {}
    ofstream :: ~ofstream(void) { delete Impl; }
    void ofstream :: open   (const std::string& fileName, ios_base::openmode om) { Impl->open(fileName,streamOpenMode2stdopenmode(om)); }
    bool ofstream :: is_open(void) const { return Impl->is_open(); }
    void ofstream :: close  (void) const { Impl->close(); }
    
    class FStreamImpl : public StreamImplTemplate<std::fstream>
    {
        public :
            using StreamImplTemplate<std::fstream>::StreamImplTemplate;
    };
    
    fstream ::  fstream(FStreamImpl* impl)
        : basic_ios(&impl->Is)
        , istream(&impl->Is)
        , ostream(&impl->Os)
        , Impl(impl)
    {
    }

    fstream ::  fstream(void) : fstream(new FStreamImpl()) {}
    fstream ::  fstream(const std::string& fileName, ios_base::openmode om)
                                : fstream(new FStreamImpl(fileName,streamOpenMode2stdopenmode(om))) {}
    fstream :: ~fstream(void) { delete Impl; }
    void fstream :: open   (const std::string& fileName, ios_base::openmode om) { Impl->open(fileName,streamOpenMode2stdopenmode(om)); }
    bool fstream :: is_open(void) const { return Impl->is_open(); }
    void fstream :: close  (void) const { Impl->close(); }
}

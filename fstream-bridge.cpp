//  self

    #include "fstream-bridge.h"

//  app

    #include "ostream-impl.h"


//  c++

    #include <array>
    #include <fstream>


namespace stream
{

    static std::array<std::pair<std::ios_base::openmode,ios_base::openmode>,6> Pairs
    {
        std::make_pair(ios_base::in    , std::ios_base::in    ),
        std::make_pair(ios_base::out   , std::ios_base::out   ),
        std::make_pair(ios_base::binary, std::ios_base::binary),
        std::make_pair(ios_base::trunc , std::ios_base::trunc ),
        std::make_pair(ios_base::app   , std::ios_base::app   ),
        std::make_pair(ios_base::ate   , std::ios_base::ate   )
    };

    static std::ios_base::openmode convert(ios_base::openmode om)
    {
        std::ios_base::openmode res=static_cast<std::ios_base::openmode>(0);
        for(const auto& p : Pairs)
        {
            if(om & p.first) res=res | p.second;
        }
        return res;
    }

    class OFStreamImpl : public OStreamImplTemplate<std::ofstream>
    {
        public :
            using OStreamImplTemplate<std::ofstream>::OStreamImplTemplate;
    };
    
    ofstream ::  ofstream(OFStreamImpl* impl)
        : ostream(&impl->os())
        , Impl(impl)
    {
    }

    ofstream ::  ofstream(void) : ofstream(new OFStreamImpl()) {}
    ofstream ::  ofstream(const std::string& fileName, ios_base::openmode om)
                                : ofstream(new OFStreamImpl(fileName,convert(om))) {}
    ofstream :: ~ofstream(void) { delete Impl; }
    void ofstream :: open   (const std::string& fileName, ios_base::openmode om) { Impl->open(fileName,convert(om)); }
    bool ofstream :: is_open(void) const { return Impl->is_open(); }
    void ofstream :: close  (void) const { Impl->close(); }
}

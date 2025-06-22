 //  self

     #include "istream-bridge.h"
 
 
 //  app
 
    #include "istream-impl.h"


//  c++

    #include <istream>
    #include <string>


namespace stream
{

  istream :: istream(IStreamImpl& impl)
    : basic_ios(impl)
    , Impl(impl)
  {
  }

  void istream::scan(char       & v)  { Impl.Is >> v; }
  void istream::scan(bool       & v)  { Impl.Is >> v; }
  void istream::scan(int        & v)  { Impl.Is >> v; }
  void istream::scan(float      & v)  { Impl.Is >> v; }
  void istream::scan(size_t     & v)  { Impl.Is >> v; }
  void istream::scan(long       & v)  { Impl.Is >> v; }
  void istream::scan(long long  & v)  { Impl.Is >> v; }
  void istream::scan(unsigned   & v)  { Impl.Is >> v; }
  void istream::scan(std::string& v)  { Impl.Is >> v; }
  
  char      istream :: get      (void)        { return Impl.Is.get(); }
  char      istream :: peek     (void) const  { return Impl.Is.peek(); }
  istream&  istream :: getline  (char* str,streamsize count) { Impl.Is.getline(str,count); return *this; }
  istream&  istream :: read     (char* str,streamsize count) { Impl.Is.read   (str,count); return *this; }
  streampos istream :: tellg    (void)        { return Impl.Is.tellg(); }
  istream&  istream :: seekg    (streampos sp){ Impl.Is.seekg(sp); return *this; }
  
}

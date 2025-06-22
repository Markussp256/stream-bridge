 //  self

     #include "ostream-bridge.h"
 
 
 //  app
 
    #include "ostream-impl.h"


//  c++

    #include <ostream>
    #include <string>


namespace stream
{



  //  ostream

  ostream :: ostream(OStreamImpl& impl)
    : basic_ios(impl)
    , Impl(impl)
  {
  }

  void ostream::print(char         v) { Impl.Os << v; }
  void ostream::print(bool         v) { Impl.Os << v; }
  void ostream::print(int          v) { Impl.Os << v; }
  void ostream::print(float        v) { Impl.Os << v; }
  void ostream::print(size_t       v) { Impl.Os << v; }
  void ostream::print(long         v) { Impl.Os << v; }
  void ostream::print(long long    v) { Impl.Os << v; }
  void ostream::print(unsigned     v) { Impl.Os << v; }
  void ostream::print(const void*  v) { Impl.Os << v; }
  void ostream::print(const char*  v) { Impl.Os << v; }
  void ostream::print(const std::string& v) { Impl.Os << v; }

  ostream& endl(ostream& os) { std::endl(os.impl().Os); return os;} 

  ostream& ostream :: put  (char c) { Impl.Os.put(c); return *this; }
  char     ostream :: fill (char c) { return Impl.Os.fill(c); }
  void     ostream :: flush(void)   { Impl.Os.flush(); }
  

  ostream* basic_ios :: tie(ostream& other)
  {
    ostream* oldTied=Tied;
    Tied=&other;
    Impl.basicIOS().tie(&other.impl().Os);
    return oldTied; 
  }
  
}

 //  self

     #include "ostream-bridge.h"
 
 
 //  app
 
    #include "ostream-impl.h"


//  c++

    #include <ostream>
    #include <iomanip>


namespace stream
{
  void ostream::print(bool        v)  { Impl->Os << std::boolalpha << v; }
  void ostream::print(int         v)  { Impl->Os << v; }
  void ostream::print(float       v)  { Impl->Os << v; }
  void ostream::print(size_t      v)  { Impl->Os << v; }
  void ostream::print(long        v)  { Impl->Os << v; }
  void ostream::print(long long   v)  { Impl->Os << v; }
  void ostream::print(unsigned    v)  { Impl->Os << v; }
  void ostream::print(const void* v)  { Impl->Os << v; }
  void ostream::print(const char* v)  { Impl->Os << v; }
  void ostream::print(setfill     sf) { Impl->Os << std::setfill(sf.C); }
  void ostream::print(endlStruct  )   { Impl->Os << std::endl; }
  void ostream::print(hexStruct   )   { Impl->Os << std::hex; }

  streamsize ostream :: width    (streamsize w) { return Impl->Os.width    (w); }
  streamsize ostream :: precision(streamsize p) { return Impl->Os.precision(p); }
  void       ostream :: put      (char       c) { Impl->Os.put      (c); }
  void       ostream :: flush    (void)         { Impl->Os.flush    (); }
  
}

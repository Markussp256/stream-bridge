 //  self

     #include "ostream-bridge.h"
 
 
 //  app
 
    #include "ostream-impl.h"


//  c++

    #include <ostream>
    #include <iomanip>


namespace stream
{
  ostream :: ostream(OStreamImpl* impl)
    : base(impl)
    , Impl(impl)
  {
  }


  void ostream::print(char            v)  { Impl->Os << v; }
  void ostream::print(bool            v)  { Impl->Os << v; }
  void ostream::print(int             v)  { Impl->Os << v; }
  void ostream::print(float           v)  { Impl->Os << v; }
  void ostream::print(size_t          v)  { Impl->Os << v; }
  void ostream::print(long            v)  { Impl->Os << v; }
  void ostream::print(long long       v)  { Impl->Os << v; }
  void ostream::print(unsigned        v)  { Impl->Os << v; }
  void ostream::print(const void*     v)  { Impl->Os << v; }
  void ostream::print(const char*     v)  { Impl->Os << v; }
  void ostream::print(setfill         sf) { Impl->Os << std::setfill(sf.C); }
  
  ostream& endl     (ostream& os) { std::endl(os.impl().Os); return os;} 
  ostream& hex      (ostream& os) { os.impl().Os.setf(std::ios_base::hex, std::ios_base::basefield); return os; }
  ostream& boolalpha(ostream& os) { os.impl().Os.setf(std::ios_base::boolalpha); return os;}


  void       ostream :: put      (char       c) { Impl->Os.put      (c); }
  void       ostream :: flush    (void)         { Impl->Os.flush    (); }
  
}

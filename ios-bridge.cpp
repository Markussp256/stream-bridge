 //  self

    #include "ios-bridge.h"
    #include "ios-bridge.h"
 
 
 //  app
 
    #include "ios-base-impl.h"


//  c++

    #include <ios>


namespace stream
{

  static std::ios_base::openmode convert(ios_base::openmode om)
  {
    std::ios_base::openmode res=static_cast<std::ios_base::openmode>(0);
#define Set(option) if(om & ios_base::option) res=res | std::ios_base::option;
    Set(in)
    Set(out)
    Set(binary)
    Set(trunc)
    Set(app)
    Set(ate)
#undef Set
      return res;
  }

  bool       base :: good         (void) const   { return Impl->Base.good         (); }
  bool       base :: eof          (void) const   { return Impl->Base.eof          (); }
  bool       base :: fail         (void) const   { return Impl->Base.fail         (); }
  bool       base :: bad          (void) const   { return Impl->Base.bad          (); }
  bool       base :: operator!    (void) const   { return Impl->Base.operator!    (); }
             base :: operator bool(void) const   { return Impl->Base.operator bool(); }
  streamsize base :: width        (streamsize w) { return Impl->Base.width        (w); }
  streamsize base :: precision    (streamsize p) { return Impl->Base.precision    (p); }
}




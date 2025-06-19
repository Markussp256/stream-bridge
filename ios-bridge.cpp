 //  self

    #include "ios-bridge.h"

 
 //  app
 
    #include "ios-base-impl.h"


//  c++

    #include <ios>


namespace stream
{

  static std::ios_base::openmode convert(ios_base::openmode om)
  {
    auto res=static_cast<std::ios_base::openmode>(0);
    auto set=[&res,om](std::ios_base::openmode nv){ if(bool(om & nv)){ res=res | nv; } };
    set(std::ios_base::in);
    set(std::ios_base::out);
    set(std::ios_base::binary);
    set(std::ios_base::trunc);
    set(std::ios_base::app);
    set(std::ios_base::ate);
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
  
  base& fixed     (base& b){ std::fixed     (b.impl().Base); return b; }
  base& scientific(base& b){ std::scientific(b.impl().Base); return b; }
  base& hex       (base& b){ std::hex       (b.impl().Base); return b; }
  base& boolalpha (base& b){ std::boolalpha (b.impl().Base); return b; }
}




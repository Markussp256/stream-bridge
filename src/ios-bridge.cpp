 //  self

    #include "ios-bridge.h"

 
 //  app
 
    #include "ios-base-impl.h"
    #include "bitmap-conversion.h"


//  c++

    #include <ios>
    #include <locale>

#define PAIR(name) std::make_pair(stream::ios_base::name, std::ios_base::name)

static const BitMapConversion<stream::ios_base::openmode,std::ios_base::openmode,6>& getOpenModeConv(void)
{
  static const BitMapConversion<stream::ios_base::openmode,std::ios_base::openmode,6> openModeConv(
    {PAIR(in    ),
     PAIR(out   ),
     PAIR(binary),
     PAIR(trunc ),
     PAIR(app   ),
     PAIR(ate   )});
  return openModeConv;
}

static const BitMapConversion<stream::ios_base::fmtflags,std::ios_base::fmtflags,15>& getFmtFlagsConv(void)
{
  static const BitMapConversion<stream::ios_base::fmtflags,std::ios_base::fmtflags,15> fmtFlagsConv(
   {PAIR(dec       ),
    PAIR(oct       ),
    PAIR(hex       ),
    PAIR(left      ),
    PAIR(right     ),
    PAIR(internal  ),
    PAIR(scientific),
    PAIR(fixed     ),
    PAIR(boolalpha ),
    PAIR(showbase  ),
    PAIR(showpoint ),
    PAIR(showpos   ),
    PAIR(skipws    ),
    PAIR(unitbuf   ),
    PAIR(uppercase )});
  return fmtFlagsConv;
}

static const BitMapConversion<stream::ios_base::iostate,std::ios_base::iostate,3>& getIOStateConv(void)
{
  static const BitMapConversion<stream::ios_base::iostate,std::ios_base::iostate,3> iostateConv(
    {PAIR(goodbit),
     PAIR(badbit ),
     PAIR(failbit)});
  return iostateConv;
}
#undef PAIR

namespace stream
{

  std::ios_base::openmode ios_base::streamOpenMode2stdopenmode(openmode om)                { return getOpenModeConv().t02T1(om); }
       ios_base::openmode ios_base::stdopenmode2streamOpenMode(std::ios_base::openmode om) { return getOpenModeConv().t12T0(om); }

  std::ios_base::fmtflags ios_base::streamFmtFlags2stdfmtflags(fmtflags om)                { return getFmtFlagsConv().t02T1(om); }
       ios_base::fmtflags ios_base::stdfmtflags2streamFmtFlags(std::ios_base::fmtflags om) { return getFmtFlagsConv().t12T0(om); }

  std::ios_base::iostate ios_base::streamIOState2stdiostate   (iostate om)                 { return getIOStateConv().t02T1(om); }
       ios_base::iostate ios_base::stdiostate2streamIOState   (std::ios_base::iostate  om) { return getIOStateConv().t12T0(om); }

  ios_base::fmtflags ios_base::flags(void) const
  {
    return stdfmtflags2streamFmtFlags(Impl.iosBase().flags());
  }
  
  ios_base::fmtflags ios_base::flags(ios_base::fmtflags flags)
  {
    return stdfmtflags2streamFmtFlags(Impl.iosBase().flags(streamFmtFlags2stdfmtflags(flags)));
  }

  ios_base::fmtflags ios_base::setf(ios_base::fmtflags flags)
  {
    return stdfmtflags2streamFmtFlags(Impl.iosBase().setf(streamFmtFlags2stdfmtflags(flags)));
  }
  
  ios_base::fmtflags ios_base::setf(ios_base::fmtflags flags,ios_base::fmtflags mask)
  {
    return stdfmtflags2streamFmtFlags(Impl.iosBase().setf(streamFmtFlags2stdfmtflags(flags),streamFmtFlags2stdfmtflags(mask)));
  }
  
  void ios_base::unsetf(ios_base::fmtflags flags)
  {
    Impl.iosBase().unsetf(streamFmtFlags2stdfmtflags(flags));
  }

  streamsize ios_base :: precision(streamsize p)        { return Impl.iosBase().precision(p); }
  streamsize ios_base :: width    (streamsize w)        { return Impl.iosBase().width    (w); }

  std::locale ios_base::imbue (const std::locale& loc ) { return Impl.iosBase().imbue(loc); }
  std::locale ios_base::getloc(void) const              { return Impl.iosBase().getloc(); }



  ios_base& fixed     (ios_base& b){ std::fixed     (b.ios_base_impl().iosBase()); return b; }
  ios_base& scientific(ios_base& b){ std::scientific(b.ios_base_impl().iosBase()); return b; }
  ios_base& hex       (ios_base& b){ std::hex       (b.ios_base_impl().iosBase()); return b; }
  ios_base& boolalpha (ios_base& b){ std::boolalpha (b.ios_base_impl().iosBase()); return b; }

  // if stream was tied it will be ignored
  basic_ios :: basic_ios(BasicIOSImpl& impl)
    : ios_base(impl)
    , Impl(impl)
    , Tied(nullptr)
  {
  }

  bool              basic_ios :: good         (void)                   const { return Impl.basicIOS().good         (); }
  bool              basic_ios :: eof          (void)                   const { return Impl.basicIOS().eof          (); }
  bool              basic_ios :: fail         (void)                   const { return Impl.basicIOS().fail         (); }
  bool              basic_ios :: bad          (void)                   const { return Impl.basicIOS().bad          (); }
  bool              basic_ios :: operator!    (void)                   const { return Impl.basicIOS().operator!    (); }
                    basic_ios :: operator bool(void)                   const { return Impl.basicIOS().operator bool(); }
  ios_base::iostate basic_ios :: rdstate      (void)                   const { return getIOStateConv().t12T0(Impl.basicIOS().rdstate      ()); }
  void              basic_ios :: setstate     (iostate state)                { Impl.basicIOS().setstate     (getIOStateConv().t02T1(state)); }
  void              basic_ios :: clear        (void)                   const { Impl.basicIOS().clear        (); }
  basic_ios&        basic_ios :: copyfmt      (const basic_ios& other)       { Impl.basicIOS().copyfmt(other.Impl.basicIOS()); return *this; }
  char              basic_ios :: fill         (void)                   const { return Impl.basicIOS().fill         (); }
  char              basic_ios :: fill         (char c)                       { return Impl.basicIOS().fill         (c); } 
  ios_base::iostate basic_ios :: exceptions   (void)                   const { return getIOStateConv().t12T0(Impl.basicIOS().exceptions   ()); }
  void              basic_ios :: exceptions   (iostate except)               { Impl.basicIOS().exceptions   (getIOStateConv().t02T1(except)); }
  std::locale       basic_ios :: imbue        (const std::locale& loc )      { return Impl.basicIOS().imbue        (loc); }
  ostream*          basic_ios :: tie          (void)                   const { return Tied; }
  char              basic_ios :: narrow       (char c, char dfault)    const { return Impl.basicIOS().narrow       (c,dfault); }
  char              basic_ios :: widen        (char c) const                 { return Impl.basicIOS().widen        (c); }
  CharStreamBuf*    basic_ios :: rdbuf        (void)                   const { return Impl.basicIOS().rdbuf(); }
  CharStreamBuf*    basic_ios :: rdbuf        (CharStreamBuf* sb)            { return Impl.basicIOS().rdbuf(sb); }
}




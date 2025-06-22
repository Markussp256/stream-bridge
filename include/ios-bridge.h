#ifndef IOS_BRIDGE_H
#define IOS_BRIDGE_H

#include <iosfwd>



namespace std
{
    class local;
    template <class CharT, class Traits> class basic_streambuf;
}

namespace stream
{
  using streamsize=std::streamsize;
  using streampos =std::streampos;
  
  using CharStreamBuf = std::basic_streambuf<char, std::char_traits<char>>;

  class IOSBaseImpl;
  struct ios_base
  {
    private   :
      IOSBaseImpl& Impl;
    protected :
      ios_base(IOSBaseImpl& impl)
        : Impl(impl)
      {
      }
    public    :
      ~ios_base(void)                         = default;
      ios_base           (const ios_base& os) = delete;
      ios_base& operator=(const ios_base& os) = delete;
      ios_base           (ios_base&& os)      = delete;
      ios_base& operator=(ios_base&& os)      = delete;

      IOSBaseImpl& ios_base_impl(void) { return Impl; }

      using openmode = unsigned;
      static constexpr openmode in     = 1 << 0; // open for reading
      static constexpr openmode out    = 1 << 1; // open for writing
      static constexpr openmode binary = 1 << 2; // open in binary mode
      static constexpr openmode trunc  = 1 << 3; // truncate file
      static constexpr openmode app    = 1 << 4; // append mode
      static constexpr openmode ate    = 1 << 5; // seek to end after open

      using fmtflags = unsigned;
      static constexpr fmtflags dec         = 1 <<  0;
      static constexpr fmtflags oct         = 1 <<  1;
      static constexpr fmtflags hex         = 1 <<  2;
      static constexpr fmtflags basefield   = dec | oct | hex;
      static constexpr fmtflags left        = 1 <<  3;
      static constexpr fmtflags right       = 1 <<  4;
      static constexpr fmtflags internal    = 1 <<  5;
      static constexpr fmtflags adjustfield = left | right | internal;
      static constexpr fmtflags scientific  = 1 <<  6;
      static constexpr fmtflags fixed       = 1 <<  7;
      static constexpr fmtflags floatfield  = scientific | fixed;
      static constexpr fmtflags boolalpha   = 1 <<  8;
      static constexpr fmtflags showbase    = 1 <<  9;
      static constexpr fmtflags showpoint   = 1 << 10;
      static constexpr fmtflags showpos     = 1 << 11;
      static constexpr fmtflags skipws      = 1 << 12;
      static constexpr fmtflags unitbuf     = 1 << 13;
      static constexpr fmtflags uppercase   = 1 << 14;

      using iostate=unsigned;
      static constexpr iostate goodbit = 0;
      static constexpr iostate badbit  = 1 << 0;
      static constexpr iostate failbit = 1 << 1;
      static constexpr iostate eofbit  = 1 << 2;

      fmtflags    flags    (void) const;
      fmtflags    flags    (fmtflags flags);
      fmtflags    setf     (fmtflags flags );
      fmtflags    setf     (fmtflags flags, fmtflags mask );
      void        unsetf   (fmtflags flags );
      streamsize  precision(streamsize p);
      streamsize  width    (streamsize w);
      std::locale imbue    (const std::locale& loc );
      std::locale getloc   (void) const;

    protected :
      static int streamOpenMode2stdopenmode(openmode);
      static int streamFmtFlags2stdfmtflags(fmtflags);
      static int streamIOState2stdiostate  (iostate);
      
      static openmode stdopenmode2streamOpenMode(int);
      static fmtflags stdfmtflags2streamFmtFlags(int);
      static iostate  stdiostate2streamIOState  (int);
  };

  ios_base& fixed     (ios_base&);
  ios_base& scientific(ios_base&);
  ios_base& hex       (ios_base&);
  ios_base& boolalpha (ios_base&);

  class ostream;
  class BasicIOSImpl;
  class basic_ios : public ios_base
  {
    private   :
      BasicIOSImpl& Impl;
      // non-owning
      ostream*      Tied;
    protected :
      basic_ios(BasicIOSImpl& impl);
    public    :
      BasicIOSImpl&  impl         (void)                           { return Impl; }
      bool           good         (void)                     const;
      bool           eof          (void)                     const;
      bool           fail         (void)                     const;
      bool           bad          (void)                     const;
      bool           operator!    (void)                     const;
                     operator bool(void)                     const;
      iostate        rdstate      (void)                     const;
      void           setstate     (iostate state);
      void           clear        (void)                     const;
      basic_ios&     copyfmt      (const basic_ios& other);
      char           fill         (void)                     const;
      char           fill         (char c);
      iostate        exceptions   (void)                     const;
      void           exceptions   (iostate except);
      std::locale    imbue        (const std::locale& loc );
      // only yields nonnull ostream* if it was tied using tie method of stream::basic_ios not if it was tied using std::basic_ios method
      // actual argument for tie is basic_ostream, but stream does not have this type 
      ostream*       tie          (void)                     const;
      ostream*       tie          (ostream& other);
      char           narrow       (char c, char dfault)      const;
      char           widen        (char c)                   const;
      
      CharStreamBuf* rdbuf        (void)                     const;
      CharStreamBuf* rdbuf        (CharStreamBuf* sb);
      
      // todo rdbuf (requires streambuf)
  };

}

#endif // IOS-BRIDGE_H

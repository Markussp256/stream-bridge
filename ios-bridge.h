#ifndef IOS_BRIDGE_H
#define IOS_BRIDGE_H

#include <iosfwd>

namespace stream
{
  using streamsize=std::streamsize;
  using streampos =std::streampos;
  
  struct ios_base
  {
    using openmode = int;
    static constexpr openmode in     = 1 << 0; // open for reading
    static constexpr openmode out    = 1 << 1; // open for writing
    static constexpr openmode binary = 1 << 2; // open in binary mode
    static constexpr openmode trunc  = 1 << 3; // truncate file
    static constexpr openmode app    = 1 << 4; // append mode
    static constexpr openmode ate    = 1 << 5; // seek to end after open
  };
  int streamOpenMode2stdOpenMode(ios_base::openmode);

  class BaseImpl;
  class base
  {
    private :
      BaseImpl* Impl;
    public  :
      base(BaseImpl* impl)
        : Impl(impl)
      {
      }
      base           (const base& os) = delete;
      base& operator=(const base& os) = delete;
      base           (base&& os)      = delete;
      base& operator=(base&& os)      = delete;
      
      bool good         (void) const;
      bool eof          (void) const;
      bool fail         (void) const;
      bool bad          (void) const;
      bool operator!    (void) const;
           operator bool(void) const;

      streamsize width    (streamsize w);
      streamsize precision(streamsize p);
  };
}

#endif // IOS-BRIDGE_H

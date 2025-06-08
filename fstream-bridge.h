#ifndef FSTREAM_BRIDGE_H
#define FSTREAM_BRIDGE_H

//  app

    #include "ostream-bridge.h"


//  c++

    #include <utility> // for std::forward
    #include <string>


namespace stream
{
  struct ios_base
  {
    using openmode = unsigned int;
    static constexpr openmode in     = 1 << 0; // open for reading
    static constexpr openmode out    = 1 << 1; // open for writing
    static constexpr openmode binary = 1 << 2; // open in binary mode
    static constexpr openmode trunc  = 1 << 3; // truncate file
    static constexpr openmode app    = 1 << 4; // append mode
    static constexpr openmode ate    = 1 << 5; // seek to end after open
  };

  class OFStreamImpl;
  class ofstream : public ostream
  {
      OFStreamImpl* Impl;
      ofstream(OFStreamImpl* impl);
    public  :
      ofstream(void);
     ~ofstream(void);
      ofstream(const std::string& fileName, ios_base::openmode om=ios_base::in);
      ofstream           (const ofstream& os) = delete;
      ofstream& operator=(const ofstream& os) = delete;
      ofstream           (ofstream&& os)      = delete;
      ofstream& operator=(ofstream&& os)      = delete;
      
      void open   (const std::string& fileName, ios_base::openmode om=ios_base::in);
      bool is_open(void) const;
      void close  (void) const;
  };

  template<typename T>
  ofstream& operator<<(ofstream& os, T&& v)
  {
      os.print(std::forward<T>(v));
      return os;
  }

}


#endif // FSTREAM-BRIDGE_H

#ifndef ISTREAM_BRIDGE_H
#define ISTREAM_BRIDGE_H

//  app

    #include "ios-bridge.h"


//  c++

    #include <utility> // for std::forward

namespace stream
{
  class IStreamImpl;
  
  
  
  class  istream : public virtual base
  {
    private :
      // istream does not own Impl hence we do not implement a destructor
      IStreamImpl* Impl;
    public  :
      istream(IStreamImpl* impl);
      
      void scan(char      );
      void scan(bool      );
      void scan(int       );
      void scan(float     );
      void scan(size_t    );
      void scan(long      );
      void scan(long long );
      void scan(unsigned  );

      char      get       (void);
      char      peek      (void) const;
      istream&  getline   (char* str, streamsize count);
      istream&  read      (char* str, streamsize count);
      streampos tellg     (void);
      istream&  seekg     (streampos sp);
  };

  template<typename T>
  istream& operator>>(istream& os, T&& v)
  {
      os.scan(std::forward<T>(v));
      return os;
  }
}



#endif // istream-BRIDGE_H

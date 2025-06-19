#ifndef SSTREAM_BRIDGE_H
#define SSTREAM_BRIDGE_H

//  app

    #include "istream-bridge.h"
    #include "ostream-bridge.h"


//  c++

    #include <string>


namespace stream
{
  class IStringStreamImpl;
  class istringstream : public istream
  {
    private :
      IStringStreamImpl* Impl;
      istringstream(IStringStreamImpl* impl);
    public  :  
      istringstream(void);
      istringstream(const std::string& str);

      std::string str(void) const;
  };

  template<typename T>
  istringstream& operator>>(istringstream& os, T& v)
  {
      os.scan(v);
      return os;
  }

  class OStringStreamImpl;
  class ostringstream : public ostream
  {
    private :
      OStringStreamImpl* Impl;
      ostringstream(OStringStreamImpl* impl);
    public  :  
      ostringstream(void);
      ostringstream(const std::string& str);

      std::string str(void) const;
  };

  template<typename T>
  ostringstream& operator<<(ostringstream& os, const T& v)
  {
      os.print(v);
      return os;
  }

  class StringStreamImpl;
  class stringstream
    : public istream
    , public ostream
  {
    private :
      StringStreamImpl* Impl;
      stringstream(StringStreamImpl* impl);    
    public  :  
      stringstream(void);
      stringstream(const std::string& str);

      std::string str(void) const;
  };

  template<typename T>
  stringstream& operator>>(stringstream& os, T& v)
  {
      os.scan(v);
      return os;
  }
  
  template<typename T>
  stringstream& operator<<(stringstream& os, const T& v)
  {
      os.print(v);
      return os;
  }
}



#endif // STRINGSTREAM-BRIDGE_H

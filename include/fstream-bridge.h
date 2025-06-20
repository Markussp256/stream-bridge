#ifndef FSTREAM_BRIDGE_H
#define FSTREAM_BRIDGE_H

//  app

    #include "istream-bridge.h"
    #include "ostream-bridge.h"
    #include "string-fwd.h"


namespace stream
{
  class IFStreamImpl;
  class ifstream : public istream
  {
      IFStreamImpl* Impl;
      ifstream(IFStreamImpl* impl);
    public  :
      ifstream    (void);
     ~ifstream    (void);
      ifstream    (const std::string& fileName, ios_base::openmode om=ios_base::in);
      void open   (const std::string& fileName, ios_base::openmode om=ios_base::in);
      bool is_open(void) const;
      void close  (void) const;
  };

  template<typename T>
  ifstream& operator>>(ifstream& is, T& v)
  {
      is.scan(v);
      return is;
  }

  class OFStreamImpl;
  class ofstream : public ostream
  {
      OFStreamImpl* Impl;
      ofstream(OFStreamImpl* impl);
    public  :
      ofstream    (void);
     ~ofstream    (void);
      ofstream    (const std::string& fileName, ios_base::openmode om=ios_base::in);
      void open   (const std::string& fileName, ios_base::openmode om=ios_base::in);
      bool is_open(void) const;
      void close  (void) const;
  };

  template<typename T>
  ofstream& operator<<(ofstream& os, const T& v)
  {
      os.print(v);
      return os;
  }

  class FStreamImpl;
  class fstream
    : public istream
    , public ostream
  {
      FStreamImpl* Impl;
      fstream(FStreamImpl* impl);
    public  :
      fstream     (void);
     ~fstream     (void);
      fstream     (const std::string& fileName, ios_base::openmode om=ios_base::in);
      void open   (const std::string& fileName, ios_base::openmode om=ios_base::in);
      bool is_open(void) const;
      void close  (void) const;
  };

  template<typename T>
  fstream& operator>>(fstream& is, T& v)
  {
      is.scan(v);
      return is;
  }

  template<typename T>
  fstream& operator<<(fstream& os, const T& v)
  {
      os.print(v);
      return os;
  }
}


#endif // FSTREAM-BRIDGE_H

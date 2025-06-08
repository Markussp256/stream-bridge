# stream-bridge
bridge pattern for c++ stream-libraries

this library allows to replace the stream includes
<iostream>
<iomanip>
<sstream>
<fstream>

with the more lightweight briges
"iostream-bridge.h"
"sstream-bridge.h"
"fstream-bridge.h"

which uses the bridge/pimpl idiom. The implemtation is straighforward by calling
the corresponding methods from the std namespace.

The bridge version is less generic/templatized, so it does not offere the same functionality
as the c++ stream libraries. Also due to additional indirection there is a small performance
loss to be paid.

The main benefit of this library is the smaller compile time for projects that have many
includes for streams. httpp.... .com compares the compile times for a demo projects

this project is far from being complete, it is at the moment just a small demonstration. 
Feel free to contribute/extend the library.

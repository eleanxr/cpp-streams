#include <iostream>

#include <DataSink.h>
#include <DataSource.h>
#include <PrintSink.h>
#include <TextFileSource.h>

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include <memory>

namespace fs = boost::filesystem;

class BridgeContext : public SourceContext< std::string >
{
public:

  BridgeContext( std::shared_ptr< DataSink< std::string > > sink )
  : mSink( sink )
  {
  }

  virtual ~BridgeContext()
  {
  }

  virtual void collect( const std::string& value ) override
  {
    mSink->output( value );
  }

private:
  std::shared_ptr< DataSink< std::string > > mSink;
};

int main( int argc, char * argv[] )
{
  if ( argc < 2 ) {
    std::cerr << "Usage: " << argv[ 0 ] << " <text-file>" << std::endl;
    return -1;
  }

  fs::path textFilePath( argv[ 1 ] );
  if ( !fs::exists( textFilePath ) ) {
    std::cerr << textFilePath << ": File does not exist." << std::endl;
  }

  auto dataSource = std::make_shared< TextFileSource >( textFilePath );
  auto dataSink = std::make_shared< PrintSink< std::string > >( std::cout );
  auto context = std::make_shared< BridgeContext >( dataSink );

  dataSource->run( *context );

  return 0;
}

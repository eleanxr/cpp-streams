#include <TextFileSource.h>

#include <iterator>
#include <fstream>

TextFileSource::TextFileSource(
  const boost::filesystem::path& path,
  const char separator,
  const OptionalSize maximumMessageLength )
: mTextFilePath( path ),
  mSeparator( separator ),
  mMaximumMessageLength( maximumMessageLength )
{
}

TextFileSource::~TextFileSource()
{
}

void TextFileSource::run(ContextType& context )
{
  std::ifstream input( mTextFilePath.string() );
  std::for_each(
     std::istream_iterator< std::string >( input ),
     std::istream_iterator< std::string >(),
     [&context]( const auto& s ) { context.collect( s ); }
  );
}

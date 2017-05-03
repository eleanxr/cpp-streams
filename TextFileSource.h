#ifndef TEXTFILESOURCE_H
#define TEXTFILESOURCE_H

#include <DataSource.h>

#include <boost/filesystem/path.hpp>
#include <boost/optional.hpp>

#include <string>

class TextFileSource : public DataSource< std::string >
{
public:

  using OptionalSize = boost::optional< std::size_t >;

  explicit TextFileSource(
    const boost::filesystem::path& path,
    const char separator = '\n',
    const OptionalSize maximumMessageLength = OptionalSize() );
  virtual ~TextFileSource();

  virtual void run( ContextType& context ) override;

private:
  const boost::filesystem::path mTextFilePath;
  const char mSeparator;
  const OptionalSize mMaximumMessageLength;
};

// Implementations


#endif // TEXTFILESOURCE_H

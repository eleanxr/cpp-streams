#ifndef PRINTSINK_H
#define PRINTSINK_H

#include <DataSink.h>

#include <ostream>

template< typename T >
class PrintSink : public DataSink< T >
{
public:
  PrintSink( std::ostream& out );
  virtual ~PrintSink();

  virtual void output( const T& value ) override;

private:
  std::ostream& mOut;
};

template< typename T >
PrintSink< T >::PrintSink( std::ostream& out )
: mOut( out )
{
}

template< typename T >
PrintSink< T >::~PrintSink()
{
}

template< typename T >
void PrintSink< T >::output( const T& value )
{
    mOut << value << std::endl;
}

#endif // PRINTSINK_H

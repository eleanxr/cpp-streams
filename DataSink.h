#ifndef DATASINK_H
#define DATASINK_H

template< typename T >
class DataSink
{
public:
  DataSink();
  virtual ~DataSink();

  virtual void output( const T& value ) = 0;
};

// Implementation
template< typename T >
DataSink< T >::DataSink()
{
}

template< typename T >
DataSink< T >::~DataSink()
{
}

#endif // DATASINK_H

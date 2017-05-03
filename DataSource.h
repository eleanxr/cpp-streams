#ifndef DATASOURCE_H
#define DATASOURCE_H

template< typename T >
class SourceContext
{
public:

  SourceContext() {}
  virtual ~SourceContext() {}

  virtual void collect( const T& value ) = 0;

};

template< typename T >
class DataSource
{
public:

  using ContextType = SourceContext< T >;

  DataSource() {}
  virtual ~DataSource() {}

  virtual void run( ContextType& context ) = 0;
};

#endif // DATASOURCE_H

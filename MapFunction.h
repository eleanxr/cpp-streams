#ifndef MAPFUNCTION_H
#define MAPFUNCTION_H

template< typename InputT, typename OutputT >
class MapFunction
{
public:
  MapFunction();
  virtual ~MapFunction();

  virtual OutputT map( const InputT& in ) = 0;
};

template< typename InputT, typename OutputT >
MapFunction< InputT, OutputT >::MapFunction()
{
}

template< typename InputT, typename OutputT >
MapFunction< InputT, OutputT >::~MapFunction()
{
}

#endif // MAPFUNCTION_H

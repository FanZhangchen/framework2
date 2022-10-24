#include "ADTotalSink.h"

registerMooseObject("framework2App", ADTotalSink);

InputParameters
ADTotalSink::validParams()
{
  auto params = ADKernel::validParams();
  params.addParam<Real>("sink", 1.0, "sink term");
  params.addParam<Real>("backstress", 1.0, "Back stress' parameter");
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial rhog}{\\partial t})$.");
  params.addCoupledVar("rhog", "The variable representing the GND dislocation density.");
  return params;
}

ADTotalSink::ADTotalSink(const InputParameters & parameters)
  : ADKernel(parameters),
    _sink(getParam<Real>("sink")),
    _backstress(getParam<Real>("backstress")),
    _rhog_grad(adCoupledGradient("rhog"))
{
}

ADReal
ADTotalSink::computeQpResidual()
{
  return _sink * _test[_i][_qp]*_u[_qp]*std::abs(_u[_qp]-_backstress*_rhog_grad[_qp](0));
}

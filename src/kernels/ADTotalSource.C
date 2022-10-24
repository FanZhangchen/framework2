#include "ADTotalSource.h"

registerMooseObject("framework2App", ADTotalSource);

InputParameters
ADTotalSource::validParams()
{
  auto params = ADKernel::validParams();
  params.addParam<Real>("source", 1.0, "Source term");
  params.addParam<Real>("backstress", 1.0, "Back stress' parameter");
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial rhog}{\\partial t})$.");
  params.addCoupledVar("rhog", "The variable representing the GND dislocation density.");
  return params;
}

ADTotalSource::ADTotalSource(const InputParameters & parameters)
  : ADKernel(parameters),
    _source(getParam<Real>("source")),
    _backstress(getParam<Real>("backstress")),
    _rhog_grad(adCoupledGradient("rhog"))
{
}

ADReal
ADTotalSource::computeQpResidual()
{
  return -_source * _test[_i][_qp]*std::sqrt(_u[_qp])*std::abs(_u[_qp]-_backstress*_rhog_grad[_qp](0));
}

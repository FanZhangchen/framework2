#include "ADTotalTrans.h"

registerMooseObject("framework2App", ADTotalTrans);

InputParameters
ADTotalTrans::validParams()
{
  auto params = ADKernel::validParams();
  params.addParam<Real>("backstress", 1.0, "Back stress' parameter");
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial rhog}{\\partial t})$.");
  params.addCoupledVar("rhog", "The variable representing the GND dislocation density.");
  return params;
}

ADTotalTrans::ADTotalTrans(const InputParameters & parameters)
  : ADKernel(parameters),
    _backstress(getParam<Real>("backstress")),
    _rhog(adCoupledValue("rhog")),
    _rhog_grad(adCoupledGradient("rhog"))
{
}

ADReal
ADTotalTrans::computeQpResidual()
{
  return _backstress * _rhog[_qp] * _rhog_grad[_qp] * 1.0 / _u[_qp] * _grad_test[_i][_qp]
    - _grad_test[_i][_qp](0) * _rhog[_qp];
}

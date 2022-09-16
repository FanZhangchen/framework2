#include "ADGNDTrans.h"

registerMooseObject("framework2App", ADGNDTrans);

InputParameters
ADGNDTrans::validParams()
{
  auto params = ADKernel::validParams();
  params.addParam<Real>("backstress", 1.0, "Back stress' parameter");
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial rhog}{\\partial t})$.");
  params.addCoupledVar("rhot", "The variable representing the total dislocation density.");
  return params;
}

ADGNDTrans::ADGNDTrans(const InputParameters & parameters)
  : ADKernel(parameters),
    _backstress(getParam<Real>("backstress")),
    _rhot(adCoupledValue("rhot"))
{
}

ADReal
ADGNDTrans::computeQpResidual()
{
  return _backstress * _grad_u[_qp]*_grad_test[_i][_qp]
    - _grad_test[_i][_qp](0) * _rhot[_qp];
}

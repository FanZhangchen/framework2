#include "ADGNDTimeDerivative.h"

registerMooseObject("framework2App", ADGNDTimeDerivative);

InputParameters
ADGNDTimeDerivative::validParams()
{
  InputParameters params = ADTimeDerivative::validParams();
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial rhog}{\\partial t})$.");
  return params;
}

ADGNDTimeDerivative::ADGNDTimeDerivative(const InputParameters & parameters)
  : ADTimeDerivative(parameters)
{
}

ADReal
ADGNDTimeDerivative::precomputeQpResidual()
{
  return ADTimeDerivative::precomputeQpResidual();
}
#include "ADTotalTimeDerivative.h"

registerMooseObject("framework2App", ADTotalTimeDerivative);

InputParameters
ADTotalTimeDerivative::validParams()
{
  InputParameters params = ADTimeDerivative::validParams();
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial rhog}{\\partial t})$.");
  return params;
}

ADTotalTimeDerivative::ADTotalTimeDerivative(const InputParameters & parameters)
  : ADTimeDerivative(parameters)
{
}

ADReal
ADTotalTimeDerivative::precomputeQpResidual()
{
  return ADTimeDerivative::precomputeQpResidual();
}
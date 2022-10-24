#pragma once

#include "ADKernel.h"

class ADTotalSource : public ADKernel
{
public:
  static InputParameters validParams();

  ADTotalSource(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual();

  const Real & _backstress;

  const Real & _source;

  const ADVariableGradient & _rhog_grad;
};

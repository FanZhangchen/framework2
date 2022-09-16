#pragma once

#include "ADKernel.h"

class ADTotalTrans : public ADKernel
{
public:
  static InputParameters validParams();

  ADTotalTrans(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual();

  const Real & _backstress;

  const ADVariableValue & _rhog;

  const ADVariableGradient & _rhog_grad;
};

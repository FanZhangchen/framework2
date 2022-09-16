#pragma once

#include "ADKernel.h"

class ADGNDTrans : public ADKernel
{
public:
  static InputParameters validParams();

  ADGNDTrans(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual();

  const Real & _backstress;

  const ADVariableValue & _rhot;
};

#pragma once

#include "ADKernel.h"

class ADTotalSink : public ADKernel
{
public:
  static InputParameters validParams();

  ADTotalSink(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual();

  const Real & _backstress;

  const Real & _sink;

  const ADVariableGradient & _rhog_grad;
};

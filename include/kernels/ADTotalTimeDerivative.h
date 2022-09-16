#pragma once

#include "ADTimeDerivative.h"

class ADTotalTimeDerivative : public ADTimeDerivative
{
public:
  static InputParameters validParams();

  ADTotalTimeDerivative(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;
};

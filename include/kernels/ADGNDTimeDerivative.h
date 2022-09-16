#pragma once

#include "ADTimeDerivative.h"

class ADGNDTimeDerivative : public ADTimeDerivative
{
public:
  static InputParameters validParams();

  ADGNDTimeDerivative(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;
};

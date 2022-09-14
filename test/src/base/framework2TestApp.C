//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "framework2TestApp.h"
#include "framework2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
framework2TestApp::validParams()
{
  InputParameters params = framework2App::validParams();
  return params;
}

framework2TestApp::framework2TestApp(InputParameters parameters) : MooseApp(parameters)
{
  framework2TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

framework2TestApp::~framework2TestApp() {}

void
framework2TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  framework2App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"framework2TestApp"});
    Registry::registerActionsTo(af, {"framework2TestApp"});
  }
}

void
framework2TestApp::registerApps()
{
  registerApp(framework2App);
  registerApp(framework2TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
framework2TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  framework2TestApp::registerAll(f, af, s);
}
extern "C" void
framework2TestApp__registerApps()
{
  framework2TestApp::registerApps();
}

#include "framework2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
framework2App::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

framework2App::framework2App(InputParameters parameters) : MooseApp(parameters)
{
  framework2App::registerAll(_factory, _action_factory, _syntax);
}

framework2App::~framework2App() {}

void
framework2App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"framework2App"});
  Registry::registerActionsTo(af, {"framework2App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
framework2App::registerApps()
{
  registerApp(framework2App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
framework2App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  framework2App::registerAll(f, af, s);
}
extern "C" void
framework2App__registerApps()
{
  framework2App::registerApps();
}

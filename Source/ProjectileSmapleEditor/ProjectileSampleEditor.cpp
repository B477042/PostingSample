#include "ProjectileSampleEditor.h"
#include "Modules/ModuleManager.h"

void FProjectileSampleEditorModule::StartupModule()
{
	IModuleInterface::StartupModule();
}

void FProjectileSampleEditorModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}

IMPLEMENT_MODULE(FProjectileSampleEditorModule, ProjectileSampleEditor);

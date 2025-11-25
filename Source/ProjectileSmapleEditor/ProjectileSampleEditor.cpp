#include "ProjectileSampleEditor.h"
#include "Modules/ModuleManager.h"

void FProjectileSampleEditorModule::StartupModule()
{
	IModuleInterface::StartupModule();
	
	FPropertyEditorModule& propertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	// クラスや構造体を登録する。
}

void FProjectileSampleEditorModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
	
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		FPropertyEditorModule& propertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		
	}
}

IMPLEMENT_MODULE(FProjectileSampleEditorModule, ProjectileSampleEditor);

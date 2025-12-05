#include "ProjectileSampleEditor.h"

#include "ClassType/AgentInfoList.h"
#include "ClassType/FMyActorDetail.h"
#include "Modules/ModuleManager.h"
#include "StructType/AgentInfoDetailPanel.h"

void FProjectileSampleEditorModule::StartupModule()
{
	IModuleInterface::StartupModule();
	
	FPropertyEditorModule& propertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	// クラスや構造体を登録する。
	
	propertyEditor.RegisterCustomClassLayout(AAgentInfoList::StaticClass()->GetFName(),FOnGetDetailCustomizationInstance::CreateStatic(&FMyActorDetail::MakeInstance));
	propertyEditor.RegisterCustomPropertyTypeLayout(FAgentInfo::StaticStruct()->GetFName(),FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FAgentInfoDetailPanel::MakeInstance));
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

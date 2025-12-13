#include "ProjectileSmapleEditor/Public/ClassType/ExtendedAgentWindowDetail.h"

#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"


TSharedRef<IDetailCustomization> FExtendedAgentWindowDetail::MakeInstance()
{
	return MakeShareable(new FExtendedAgentWindowDetail);
}

void FExtendedAgentWindowDetail::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<FName> allCategoryNames;
	DetailBuilder.GetCategoryNames(allCategoryNames);
	for (const FName& categoryName : allCategoryNames)
	{
		if (categoryName != FName("Data"))
		{
			DetailBuilder.HideCategory(categoryName);
		}
	}
	auto& it = DetailBuilder.EditCategory(FName("TransformCommon"));
	it.SetCategoryVisibility(false);
	// TSharedPtr<IPropertyHandle> temp;
	// DetailBuilder.EditDefaultProperty(temp);

}

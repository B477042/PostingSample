#pragma once
#include "CoreMinimal.h"
#include "Interface/IGasModel.h"
#include "Interface/IGasPresenter.h"
#include "Interface/IGasView.h"

class FSystemHolder final : public TSharedFromThis<FSystemHolder>
{
public:
	FSystemHolder();
	~FSystemHolder();
	template <typename InterfaceName>
	const TSharedPtr<InterfaceName> GetSystem() const ;
	
	void InitSystemHolder();
	void ResetSystemHolder();
	
private:
	
	
	template <typename InterfaceName>
	void setSystem(TSharedPtr<InterfaceName> newSystemObject) ;
	void setGasModel (TSharedPtr<IGasModel> newGasModel) ;
private:
	TSharedPtr<IGasPresenter> gasPresenter;
	TSharedPtr<IGasModel> gasModel;
	TSharedPtr<IGasView> gasView;
	
};

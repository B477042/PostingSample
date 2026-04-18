#pragma once
#include "CoreMinimal.h"
#include "Interface/IGasModel.h"
#include "Interface/IGasPresenter.h"
#include "Interface/IGasView.h"


class FSystemHolder final : public TSharedFromThis<FSystemHolder>
{
public:

	~FSystemHolder();

	static TSharedPtr<FSystemHolder> Get()
	{
		if (instance==nullptr)
		{
			instance = MakeShareable(new FSystemHolder());
		}
		return instance;
	}
	
	FSystemHolder(const FSystemHolder&) = delete;
	FSystemHolder& operator=(const FSystemHolder&) = delete;
	FSystemHolder(const FSystemHolder&&) = delete;
	FSystemHolder& operator=(const FSystemHolder&&) = delete;
	
	void InitSystemHolder();
	void ResetSystemHolder();
	
private:
	FSystemHolder() = default;
	static TSharedPtr<FSystemHolder> instance;
	void setGasModel (TSharedPtr<IGasModel> newGasModel) ;
public:
	
	template <typename InterfaceName>
	TSharedPtr<InterfaceName> GetSystem() const
	{
		if constexpr (std::is_same_v<InterfaceName, IGasModel>)
		{
			return gasModel;
		}
	
		else if constexpr (std::is_same_v<InterfaceName, IGasPresenter>)
		{
			return gasPresenter;
		}
	
		else if constexpr (std::is_same_v<InterfaceName, IGasView>)
		{
			return gasView;
		}
	
		else
		{
			nullptr;
		}
	}
	
private:
	template <typename InterfaceName>
	void setSystem(TSharedPtr<InterfaceName> newSystemObject)
	{
		if constexpr (std::is_same_v<InterfaceName, IGasModel>)
		{
			gasModel = newSystemObject;
		}
	
		else if constexpr (std::is_same_v<InterfaceName, IGasPresenter>)
		{
			gasPresenter = newSystemObject;
		}
	
		else if constexpr (std::is_same_v<InterfaceName, IGasView>)
		{
			gasView = newSystemObject;
		}
	}
private:
	TSharedPtr<IGasPresenter> gasPresenter;
	TSharedPtr<IGasModel> gasModel;
	TSharedPtr<IGasView> gasView;
	
};

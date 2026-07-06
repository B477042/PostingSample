#pragma once

enum class E_GameAbilityType : uint8;

class IGasModel
{
public:
	IGasModel();
	virtual ~IGasModel(){}
	
	virtual void Initialize() = 0;
	
	virtual const TArray<E_GameAbilityType>& GetPlayerDefaultAbilityType()=0;
};

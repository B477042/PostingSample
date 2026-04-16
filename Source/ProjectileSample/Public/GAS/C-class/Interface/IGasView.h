#pragma once

class IGasView
{
public:
	IGasView(){}
	virtual ~IGasView(){}
	
	virtual void Initialize()=0;
	virtual void OnLoadPlayerAbility()=0;
};

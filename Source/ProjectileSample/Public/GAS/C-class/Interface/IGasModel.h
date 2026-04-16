#pragma once

class IGasModel
{
public:
	IGasModel(){}
	virtual ~IGasModel(){}
	
	virtual void Initialize()=0;
};

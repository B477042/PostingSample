#pragma once

class IGasPresenter
{
public:
	IGasPresenter(){}
	virtual ~IGasPresenter(){}
	
	virtual void Initialize()=0;
};

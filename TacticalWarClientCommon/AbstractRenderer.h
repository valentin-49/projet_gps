#pragma once
class AbstractRenderer
{
public:
	AbstractRenderer();
	virtual ~AbstractRenderer();

	virtual void render() = 0;
};


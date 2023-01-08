#pragma once
class IsaacPlay
{
public:
	IsaacPlay();
	~IsaacPlay();

	IsaacPlay(const IsaacPlay& _Other) = delete;
	IsaacPlay(IsaacPlay&& _Other)noexcept = delete;
	IsaacPlay operator=(IsaacPlay&& _Other) = delete;
	IsaacPlay operator=(const IsaacPlay& _Other) noexcept= delete;
protected:

private:
};


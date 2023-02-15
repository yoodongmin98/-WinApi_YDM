#pragma once
#include <GameEngineCore/GameEngineActor.h>


class Room : public GameEngineActor
{
public:
	// constrcuter destructer
	Room();
	~Room();

	// delete Function
	Room(const Room& _Other) = delete;
	Room(Room&& _Other) noexcept = delete;
	Room& operator=(const Room& _Other) = delete;
	Room& operator=(Room&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};


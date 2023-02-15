#pragma once
#include <GameEngineCore/GameEngineActor.h>

struct TileIndex
{
	union 
	{
		struct 
		{
			int X;
			int Y;
		};

		__int64 TileKey;
	};
};

enum class ROOMDIR
{
	LEFT,
	RIGHT,
	Up,
	DOWN,
	MAX,
};


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

	void SetTileIndex(int _X, int _Y)
	{
		Index.X = _X;
		Index.Y = _Y;
	}

protected:
	void Start() override;

private:
	TileIndex Index;

	Room* LinkRoom[static_cast<int>(ROOMDIR::MAX)] = {};
};


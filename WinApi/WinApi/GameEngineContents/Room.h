#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <map>


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


class GameEngineRender;
class GameEngineCollision;
class Room : public GameEngineActor
{
private:
	static const TileIndex DirRoomIndex[4];
	static std::map<__int64, Room*> AllRoom;

public:
	
	static void RoomCreateStart();
	// constrcuter destructer
	Room();
	~Room();

	// delete Function
	Room(const Room& _Other) = delete;
	Room(Room&& _Other) noexcept = delete;
	Room& operator=(const Room& _Other) = delete;
	Room& operator=(Room&& _Other) noexcept = delete;

	void SetTileIndex(int _X, int _Y, int _MapKey);
	void Render(float _DeltaTime);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	TileIndex Index;

	Room* LinkRoom[static_cast<int>(ROOMDIR::MAX)] = {};

	GameEngineRender* DoorRenderer[static_cast<int>(ROOMDIR::MAX)] = {};
	GameEngineCollision* DoorCollision[static_cast<int>(ROOMDIR::MAX)] = {};

	GameEngineCollision* ThisDoorCollision = nullptr;
	GameEngineCollision* LinkDoorCollision = nullptr;




	GameEngineRender* ThisDoorUpRender			= nullptr;
	GameEngineRender* ThisDoorLeftRender		= nullptr;
	GameEngineRender* ThisDoorRightRender		= nullptr;
	GameEngineRender* ThisDoorDownRender		= nullptr;
												
	GameEngineRender* ThisBossDoorLeftRender	= nullptr;
	GameEngineRender* ThisBossDoorRightRender	= nullptr;
												
	GameEngineRender* LinkDoorUpRender			= nullptr;
	GameEngineRender* LinkDoorLeftRender		= nullptr;
	GameEngineRender* LinkDoorRightRender		= nullptr;
	GameEngineRender* LinkDoorDownRender		= nullptr;
												
	GameEngineRender* LinkBossDoorRightRender	= nullptr;
	GameEngineRender* LinkBossDoorLeftRender	= nullptr;
};


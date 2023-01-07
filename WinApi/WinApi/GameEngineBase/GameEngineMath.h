#pragma once


// final 더이상 상속내리지 못한다.
// 상속도 못하고 만들지도 못하게 만든 상태로
// 변하지않는 static값만 넣어주는곳.
class GameEngineMath final 
{
public:
	static const float PIE; //파이값
	static const float PIE2;//파이x2(제곱아님)

private:
	virtual ~GameEngineMath() = 0; 
};

class float4
{
public:
	static const float4 Left;
	static const float4 Right;
	static const float4 Up;
	static const float4 Down;
	static const float4 Forward; //아직안씀
	static const float4 Back; //2222

public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 1.0f;
	// 마지막이 1인지는 3d 때 배우게 될겁니다.


	//값을 인트값으로 리턴해주는함수들
	int ix() {
		return static_cast<int>(x);
	}

	int iy() {
		return static_cast<int>(y);
	}

	int iz() {
		return static_cast<int>(z);
	}

	int iw() {
		return static_cast<int>(w);
	}

	float4 half() //절반값을 리턴하는 함수
	{
		return { x * 0.5f,y * 0.5f,z * 0.5f,w };
	}

	float4 operator *(const float _Value) const //*오퍼레이터
	{
		float4 Return;
		Return.x = x * _Value;
		Return.y = y * _Value;
		Return.z = z * _Value;
		return Return;
	}


	float4& operator +=(const float4& _Other) //+ 오퍼레이터
	{
		x += _Other.x;
		y += _Other.y;
		z += _Other.z;
		return *this;
	}
};
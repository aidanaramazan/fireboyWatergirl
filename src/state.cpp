#include <iostream>
#include <vector>
using namespace std;
#include <DirectXMath.h>
#include <Windows.h>
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
using namespace DirectX;

DirectX::XMFLOAT3 position;
DirectX::XMFLOAT3 velocity;
int health;
   int score;
   int gemsCollected;
   bool onGround;
   void move();
   void jump();

void move()
 {
     float deltaTime = DirectX::XMFLOAT3 newPosition(
         position.x + velocity.x * deltaTime,
         position.y + velocity.y * deltaTime,
         position.z + velocity.z * deltaTime
     );

     position = newPosition;
 }

 void jump()
 {
     if (onGround)
     {
         velocity.y = jumpVelocity;
         onGround = false;
     }
 }

class Watergirl {
	const float jumpVelocity = 10.0f;
	 const float moveSpeed = 5.0f;

};

int main() {
	Player fireBoy(fireBoyTexture, 1), waterGirl(waterGirlTexture, 2);

	 if (fireBoy.isDead || waterGirl.isDead)
	        {
	            deathCounter++;
	        }
	 if (deathCounter >= (1.5 * iterationsPerSecond))
	        {
	            paused = 1;
	            deathCounter = 0;
	        }

 return 0;
}

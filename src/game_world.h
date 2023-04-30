#ifndef GAME_WORLD_H
#define GAME_WORLD_H
#include <vector>
#include <DirectXMath.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int PAUSE_MENU_WIDTH = 400;
const int PAUSE_MENU_HEIGHT = 300;


class GameWorld {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Fireboy and Watergirl");
	std::unordered_map<int, std::pair<sf::Sprite, sf::Vector2f>> gemObjects = {
	    { 0, { gemSprite1, { 100.f, 200.f } } },
	    { 1, { gemSprite2, { 300.f, 400.f } } },
	};
	std::vector<bool> gemsTaken(gemObjects.size(), false);

    class Sprite {
    public:
        Sprite(DirectX::XMFLOAT3 position, float width, float height, ID3D11ShaderResourceView* texture);
        DirectX::XMFLOAT3 position;
        float width;
        float height;
        ID3D11ShaderResourceView* texture;
        void draw(ID3D11DeviceContext* deviceContext);

    private:
        ID3D11Buffer* vertexBuffer;
        ID3D11Buffer* indexBuffer;
        void initializeBuffers(ID3D11Device* device);
    };

public:
	GameWorld(int width, int height, std::string title);
	~GameWorld();
	bool isRunning();
	void handleEvents();
	void update();
	void draw();

private:
    struct Player
    {
        int jumpCnt = jumpFactor, ready = 1, groundCheck = 1;
        Sprite playerSprite;
        float dx, dy;
        int type;
        bool isDead = 0;
            void Inquire()
            {
                bounds = playerSprite.getGlobalBounds();
                dx = playerSprite.getPosition().x;
                dy = playerSprite.getPosition().y;

                if (dx > 1160)
                    playerSprite.setPosition({1160, dy});
                if (dx < 40)
                    playerSprite.setPosition({40, dy});

            }
            void move(pair<float, float> coordinates)
              {
                  playerSprite.move({coordinates.first,coordinates.second});
              }
              void die()
              {
                  isDead = 1;
                  playerSprite.setPosition(2000, 2000);

              }
};

    void renderPauseBackground()
    {
    	LPDIRECT3DTEXTURE9 pauseMenuTexture; // Declare a variable to hold the pause menu texture

    	HRESULT result = D3DXCreateTextureFromFile(sprite, "pause_menu_texture.png", &pauseMenuTexture);

        if (gameStarted && paused)
        {
            D3DXCOLOR color = D3DXCOLOR(0, 0, 0, 0.5f);
            RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
            sprite->Draw(backgroundTexture, &rect, nullptr, nullptr, color);

            RECT pauseMenuRect = { SCREEN_WIDTH / 2 - PAUSE_MENU_WIDTH / 2,
                                   SCREEN_HEIGHT / 2 - PAUSE_MENU_HEIGHT / 2,
                                   SCREEN_WIDTH / 2 + PAUSE_MENU_WIDTH / 2,
                                   SCREEN_HEIGHT / 2 + PAUSE_MENU_HEIGHT / 2 };
            sprite->Draw(pauseMenuTexture, &pauseMenuRect, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
        }
    }

    void renderGems()
    {
        for (auto i : gemObjects)
        {
            if (!gemsTaken[i.second])
            {
                window.draw(i.first.first);
            }
        }
    }

    void renderDoor()
    {
        window.draw(spriteDoor);
    }

};
#endif

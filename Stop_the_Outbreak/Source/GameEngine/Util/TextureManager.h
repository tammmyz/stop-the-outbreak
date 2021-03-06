#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,

			Menu_bg,
			SortGarbage_bg,
			WFH_bg,
			WashYoHands_bg,
			PutOnMask_bg,
			Blank_bg,
			Mask_1,
			Mask_2,
			Mask_3,

			Garbage,
			Compost,
			Recycling,
			BananaPeel,
			AluminumCan,
			Bottle,
			ChipBag,
			Fish,
			GarbageBall,
			Face,
			Mask,
			Hands,
			SoapyHands,
			ShinyHands,
			Water,

			Count,
		};
	}

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::type::Menu_bg: return "Menu.png";
		case eTexture::type::SortGarbage_bg: return "Recycling Instructions.png";
		case eTexture::type::WFH_bg: return "Monitor_WFH.png";
		case eTexture::type::WashYoHands_bg: return "Wash Hands Instructions 2.png";
		case eTexture::type::PutOnMask_bg: return "Mask Instructions.png";
		case eTexture::type::Blank_bg: return "Sourdough Instructions.png";
		case eTexture::type::Mask_1: return "1_Mask.png";
		case eTexture::type::Mask_2: return "2_Masks.png";
		case eTexture::type::Mask_3: return "3_Masks.png";

		case eTexture::type::Garbage: return "Garbage_Bin.png";
		case eTexture::type::Compost: return "Compost_Pit.png";
		case eTexture::type::Recycling: return "Recycling_Sign.png";
		case eTexture::type::BananaPeel: return "Banana_Peel.png";
		case eTexture::type::AluminumCan: return "Aluminum_Can.png";
		case eTexture::type::Bottle: return "Bottle.png";
		case eTexture::type::ChipBag: return "Chip_Bag.png";
		case eTexture::type::Fish: return "Fish.png";
		case eTexture::type::GarbageBall: return "Garbage_Ball.png";
		case eTexture::type::Face: return "Face.png";
		case eTexture::type::Mask: return "mask.png";
		case eTexture::type::Hands: return "Hands.png";
		case eTexture::type::SoapyHands: return "Shiny Hands.png";
		case eTexture::type::ShinyHands: return "Soapy Hands.png";
		case eTexture::type::Water: return "Possible Raindrops.png";

		}
		return "UnknownTexType";
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}


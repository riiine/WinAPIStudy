#include "AssetManager.h"

namespace FlappyBirdGame
{
	/** _textures map 컨테이너에 name을 키로 해서 texture를 추가해주는 함수를 정의합니다.*/
	void AssetManager::LoadTexture(string name, string fileName)
	{
		/** 텍스쳐를 저장할 임시 변수를 선언합니다. */
		sf::Texture tex;
		/**
		참조 타입은 꼭 nullptr체를 해야만 합니다.
		1. 값타입(int, float, double, bool)은 변수만 선언하고 내가 값을 주지 않더라도
		기본 값이 들어갑니다.
		2. 참조타입은 변수만 선언하고 내가 초기값을 주지 않으면 nullptr입니다.
		C++은 nullptr인데 접근하면 에러가 생깁니다.

		참조타입에서 꼭 if문으로 nullptr체크를 해야하는 이유입니다.
		*/
		/** 만일 텍스쳐 로드가 성공했다면? */
		if (tex.loadFromFile(fileName))
		{
			/** _textures map 컨테이너에 name을 키로 해서 texture를 추가해줍니다. */
			this->_textures[name] = tex;
		}
	}

	/** _textures map 컨테이너에서 name을 키로 value값인 texture를 반환하는 함수를 정의합니다.*/
	sf::Texture& AssetManager::GetTexture(string name)
	{
		/** _textures map 컨테이너에서 name을 키로 value값인 texture를 반환합니다. */
		return this->_textures.at(name);
	}

	/** _fonts map 컨테이너에 name을 키로 해서 font를 추가해주는 함수를 정의합니다.*/
	void AssetManager::LoadFont(string name, string fileName)
	{
		sf::Font font;
		/** 만일 font에셋 로드가 성공했다면? */
		if (font.loadFromFile(fileName))
		{
			/** _fonts map 컨테이너에 name을 키로 해서 font에셋을 추가해줍니다. */
			this->_fonts[name] = font;
		}
	}

	/** _fonts map 컨테이너에서 name을 키로 value값이 font를 반환하는 함수를 정의합니다.*/
	sf::Font& AssetManager::GetFont(string name)
	{
		/** _fonts map 컨테이너에서 name을 키로 value값인 font를 반환합니다. */
		return this->_fonts.at(name);
	}
}
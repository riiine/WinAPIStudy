#include "AssetManager.h"

namespace FlappyBirdGame
{
	/** _textures map �����̳ʿ� name�� Ű�� �ؼ� texture�� �߰����ִ� �Լ��� �����մϴ�.*/
	void AssetManager::LoadTexture(string name, string fileName)
	{
		/** �ؽ��ĸ� ������ �ӽ� ������ �����մϴ�. */
		sf::Texture tex;
		/**
		���� Ÿ���� �� nullptrü�� �ؾ߸� �մϴ�.
		1. ��Ÿ��(int, float, double, bool)�� ������ �����ϰ� ���� ���� ���� �ʴ���
		�⺻ ���� ���ϴ�.
		2. ����Ÿ���� ������ �����ϰ� ���� �ʱⰪ�� ���� ������ nullptr�Դϴ�.
		C++�� nullptr�ε� �����ϸ� ������ ����ϴ�.

		����Ÿ�Կ��� �� if������ nullptrüũ�� �ؾ��ϴ� �����Դϴ�.
		*/
		/** ���� �ؽ��� �ε尡 �����ߴٸ�? */
		if (tex.loadFromFile(fileName))
		{
			/** _textures map �����̳ʿ� name�� Ű�� �ؼ� texture�� �߰����ݴϴ�. */
			this->_textures[name] = tex;
		}
	}

	/** _textures map �����̳ʿ��� name�� Ű�� value���� texture�� ��ȯ�ϴ� �Լ��� �����մϴ�.*/
	sf::Texture& AssetManager::GetTexture(string name)
	{
		/** _textures map �����̳ʿ��� name�� Ű�� value���� texture�� ��ȯ�մϴ�. */
		return this->_textures.at(name);
	}

	/** _fonts map �����̳ʿ� name�� Ű�� �ؼ� font�� �߰����ִ� �Լ��� �����մϴ�.*/
	void AssetManager::LoadFont(string name, string fileName)
	{
		sf::Font font;
		/** ���� font���� �ε尡 �����ߴٸ�? */
		if (font.loadFromFile(fileName))
		{
			/** _fonts map �����̳ʿ� name�� Ű�� �ؼ� font������ �߰����ݴϴ�. */
			this->_fonts[name] = font;
		}
	}

	/** _fonts map �����̳ʿ��� name�� Ű�� value���� font�� ��ȯ�ϴ� �Լ��� �����մϴ�.*/
	sf::Font& AssetManager::GetFont(string name)
	{
		/** _fonts map �����̳ʿ��� name�� Ű�� value���� font�� ��ȯ�մϴ�. */
		return this->_fonts.at(name);
	}
}